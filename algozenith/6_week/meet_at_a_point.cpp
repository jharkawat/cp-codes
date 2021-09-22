#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n; cin>>n;
    ll x,y;
    ll dx[n], dy[n];
    for(ll i=0; i<n; i++)
    {
        cin >> dx[i];
        cin >> dy[i];
    }    
    sort(dx, dx+n);
    sort(dy, dy+n);

    x = dx[n/2];
    y = dy[n/2];

    ll ans = 0;
    for(ll i=0; i<n; i++)
    {
        ans += (abs(dx[i]-x) + abs(dy[i]-y));
        // cout << dx[i] << " " << x << " " <<dy[i] << " " << y << endl;
        // cout << abs(dx[i]-x) << " " << abs(dy[i]-y) << endl;
        // cout << ans << endl;
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