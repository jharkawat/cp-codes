#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,k;
ll dp[1010][1010][2];
ll const mod = 1e9+7;

ll rec(ll level, ll taken, ll parity)
{
    // base case
    if(level == n)
    {
        // cout << level << " " << taken << " " << parity << " final"  <<"\n" ; 
        return 1;
    }

    // cache
    if(dp[level][taken][parity] != -1)
    {
        return dp[level][taken][parity];
    }

    ll ans = 0;
    if(taken == k)
    {
        ans += rec(level+1, 1, parity^1);
    }
    else
    {
        ans += rec(level+1, taken+1, parity);
        ans += rec(level+1, 1, parity^1);
    }

    // save and return 
    // cout << level << " " << taken << " " << parity << " " << ans << "\n" ;
    return dp[level][taken][parity] = ans%mod;
}

void solve()
{
    cin >> n >> k;
    memset(dp,-1,sizeof(dp));
    ll ans =  (rec(1,1,0)+rec(1,1,1))%mod;
    cout << ans << "\n";
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