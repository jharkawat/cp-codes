#include <bits/stdc++.h>
using namespace std;
using ll = long long; 

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    ll n;
    cin >> n;
    ll mis1 = 0;
    ll mis2 = 0;
    for(ll i=0; i<n; i++)
    {
        ll p;
        cin >> p;
        mis1 ^= p;
    }
    for(ll i=0; i<n-1; i++)
    {
        ll p;
        cin >> p;
        mis1 ^= p;
        mis2 ^= p;
    }
    for(ll i=0; i<n-2; i++)
    {
        ll p;
        cin >> p;
        mis2 ^= p;
    }

    cout << mis1 << " " << mis2 << '\n';
}

signed main()
{
    IOS
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}