#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n; cin >> n;
    map<ll,ll> mpp;
    for(ll i=0; i<n; i++)
    {
        ll temp; cin >> temp;
        mpp[temp]++; 
    }
    ll mid = n/2;
    ll ans = -1;
    for(auto x: mpp)
    {
        if(x.second>mid)
        {
            ans = x.second;
            break;
        }
    }
    if(ans != -1) cout << (n-ans)*2 << endl;
    else cout << n << endl;
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