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
    while(n--)
    {
        ll p; cin >> p;
        mpp[p]++;
    }    
    ll ans = 0;
    for(auto x:mpp)
    {
        if(x.first > x.second)
        {
            ans += x.second;
        }
        else if(x.first < x.second)
        {
            ans += x.second-x.first;
        }
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

    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}