#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,k;
ll dp[110][110][110];
ll const mod = 1e9+7;

ll rec(ll level, ll sum, ll num)
{
    // pruning
    if(sum>n || num>n)
    {
        return 0;
    }

    // base case
    if(level == k)
    {
        if(sum == n)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }

    // cache
    if(dp[level][sum][num] != -1)
    {
        return dp[level][sum][num];
    }

    // logic
    ll ans = 0;
    if(num == n)
    {
        if((n-sum) >= num)
        {
            ans += rec(level+1, sum+num, num);
        }
    }
    else
    {
        if((n-sum) >= num)
        {
            ans += rec(level+1, sum+num, num);
            ans += rec(level, sum, num+1);
        }
    }
    ans = ans%mod;

    // cout << level << " " << sum << " " << num << " " << ans << "\n";
    // save and return 
    return dp[level][sum][num] = ans;

}

void solve()
{
    cin >> n >> k;
    memset(dp,-1,sizeof(dp));
    cout << rec(0,0,0) << "\n";
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