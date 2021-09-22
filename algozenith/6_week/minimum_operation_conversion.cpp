#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll x,y;
    cin >> x >> y;
    ll ans=0;
    while(y>x)
    {
        if(y%2)
        {
            y++;
            ans++;
        }
        y /= 2;
        ans++;
    }    
    ans += (x-y);
    cout << ans << '\n';
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