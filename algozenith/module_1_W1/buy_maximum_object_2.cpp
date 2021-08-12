#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> vec(n);
    for(ll i=0; i< n; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    vector<ll> prefix_arr(n);
    for(ll i=0; i< n; i++)
    {
        if(!i)
        {
            prefix_arr[i] = vec[i];
        }
        else{
            prefix_arr[i] = prefix_arr[i-1] + vec[i];
        }
    }
    while(k--)
    {
        ll m;
        cin >> m;
        cout << upper_bound(prefix_arr.begin(),prefix_arr.end(),m)-prefix_arr.begin() << endl;
    }
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