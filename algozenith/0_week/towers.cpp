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
    multiset<ll> towers;
    while(n--)
    {
        ll x; cin>> x;
        if(towers.empty() || towers.upper_bound(x) == towers.end())
        {
            towers.insert(x);
        }
        else
        {
            towers.erase(towers.upper_bound(x));
            towers.insert(x);
        }
    }
    cout << (ll)towers.size() << "\n";
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}