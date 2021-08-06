#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

ll number_to_find(ll x)
{
    ll ans = 1;
    while(ans<x)
    {
        ans *= 2;
    }
    return (ans-x);
}

void solve()
{
    ll n; cin >> n;
    map<ll,vector<ll>> mpp;
    for(ll i=0; i<n; i++)
    {
        ll p; cin >> p;
        mpp[p].push_back(i);
    }
    auto it = mpp.end();
    for(ll i=0; i<n; i++)
    {
        it--;
        
    }
    
    
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}