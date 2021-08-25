#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n,x;
    cin >> n >> x;
    vector<ll> arr1, arr2;
    for(ll i=0; i<n; i++)
    {
        ll temp;
        cin>> temp;
        if(i%2==0)
        {
            arr1.push_back(temp);
        }
        else
        {
            arr2.push_back(temp);
        }
    }
    vector<ll> sum1,sum2;
    ll m = (ll)arr1.size();
    for(ll i=0; i< (1<<m); i++)
    {
        ll sum =0;
        for(ll j=0; j<m; j++)
        {
            if((i>>j)&1) sum += arr1[j];
        }
        sum1.push_back(sum%x);
    }

    m = (ll)arr2.size();
    for(ll i=0; i< (1<<m); i++)
    {
        ll sum =0;
        for(ll j=0; j<m; j++)
        {
            if((i>>j)&1) sum += arr2[j];
        }
        sum2.push_back(sum%x);
    }
    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());

    ll ans =0;
    for(auto v : sum1)
    {
        auto it = upper_bound(sum2.begin(),sum2.end(),(x-v-1));
        it--;
        ans = max(ans,(v+*it));
    }

    cout << ans << endl;

}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    solve();

}