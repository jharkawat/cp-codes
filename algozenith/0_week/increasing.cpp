#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    ll n;
    cin >> n;
    ll sum = 0;
    ll maxi = INT16_MIN;
    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >> t;
        maxi = max(maxi,t);
        sum += maxi-t;
    }
    cout << sum << "\n";
}

signed main()
{
    IOS
    ll t; cin >> t;
    while(t--)
    {
        solve();
    }
}