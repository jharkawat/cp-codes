#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

ll const mod = 1e9+7;

void solve()
{
    ll n,m;
    cin >> n >> m;
    ll la;
    ll ans = 0;
    for(ll i=1; i<n; i = la+1)
    {
        la = n/(n/i);
        ll power = m;
        ll temp = 1;
        ll x= (n/i)%mod;
        while(power>0)
        {
            if(power&1)
            temp = (temp*x)%mod;

            x = (x*x)%mod;
            power >>= 1;
        }
        ll mult = (la-i+1 + mod)%mod ;
        ans += (mult*temp)%mod;
        ans = ans%mod;
    }
    cout << ans << '\n';
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    

    solve();
}