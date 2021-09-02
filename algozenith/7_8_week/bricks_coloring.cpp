#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,m,k;
ll dp[2020][2020];
ll const mod = 1e9+7;

ll rec(ll level, ll diff_left)
{
    if(level == n)
    {
        if(diff_left == 0)
        return 1;
        else
        return 0;
    }
    if(dp[level][diff_left] != -1)
    {
        return dp[level][diff_left];
    }
    ll ans = (rec(level+1,diff_left) + ((m-1)*(rec(level+1,diff_left-1)))%mod)%mod;
    // cout << level << " " << diff_left << " " << ans << endl;
    return dp[level][diff_left] = ans; 
}

void solve()
{
    cin >> n >> m >> k;
    for(ll i=0; i<=n; i++)
    {
        for(ll j=0; j<=k; j++)
        {
            dp[i][j] = -1;
        }
    }
    // memset(dp,-1,sizeof(dp));
    cout << m*rec(1,k) << endl;

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