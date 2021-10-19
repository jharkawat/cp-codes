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
    ll a[n], b[n];
    for(ll i=0; i<n; i++) cin >> a[i];    
    for(ll i=0; i<n; i++) cin >> b[i];    
    sort(a, a+n);
    sort(b, b+n, greater<ll>());
    ll sum = 0;
    for(ll i=0; i<n; i++) sum += a[i]*b[i];
    cout << sum << '\n';
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