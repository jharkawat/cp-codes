#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n,k; cin >> n >> k;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }    
    ll ans = 0; 
    for(ll i=30; i>=0; i--)
    {
        vector<ll> sec;
        for(auto x : arr)
        {
            if(x&(1LL<<i))
            {
                // cout << x << " ";
                sec.push_back(x);
            }
        }
        if(sec.size()>=k)
        { 
            ans |= (1<<i);
            arr = sec;
        }
    }
    cout << ans << endl;
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    // solve();

    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}