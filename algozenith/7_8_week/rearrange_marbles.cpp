#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n1,n2, k1,k2;
ll dp[101][101][2];
ll const mod = 1e8;

ll rec(ll g_left, ll r_left, ll type)
{
    if(g_left == 0 && r_left == 0)
    {
        return 1;
    }
    if(dp[g_left][r_left][type] != -1)
    {
        return dp[g_left][r_left][type];
    }
    ll ans = 0;
    if(type == 0)
    {
        for(ll i=1; i<=min(g_left,k1); i++)
        {
            ans += rec(g_left-i,r_left,1);
        }
    }
    else if(type == 1)
    {
        for(ll i=1; i<=min(r_left,k2); i++)
        {
            ans += rec(g_left,r_left-i,0);
        }
    }
    return dp[g_left][r_left][type] = ans%mod;
}

void solve()
{
    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp,-1,sizeof(dp));
    ll ans = (rec(n1,n2,0)+rec(n1,n2,1))%mod;
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