#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

ll dp[200100][5];
ll n;
ll const mod = 1e9+7;

ll rec(ll level, ll letter)
{
    // pruning

    // base case
    if(level == 0)
    {
        return 1;
    }

    // cache
    if(dp[level][letter] != -1)
    {
        return dp[level][letter];
    }

    //  logic
    ll ans = 0;
    if(letter == 0)
    {
        ans = rec(level-1,2) + rec(level-1,3) + rec(level-1,4);
    }
    else if(letter == 1)
    {
        ans = rec(level-1,0) + rec(level-1,2) + rec(level-1,3);
    }
    else if(letter == 2)
    {
        ans = rec(level-1,1) + rec(level-1,3);
    }
    else if(letter == 3)
    {
        ans = rec(level-1,1) + rec(level-1,3);
    }
    else if(letter == 4)
    {
        ans = rec(level-1,2) + rec(level-1,3);
    }
    ans = ans%mod;
    return dp[level][letter] = ans;
}

void solve()
{
    cin >> n;
    ll ans = (rec(n-1,0) + rec(n-1,1) + rec(n-1,2) + rec(n-1,3) + rec(n-1,4))%mod;
    cout << ans << '\n';
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    memset(dp,-1,sizeof(dp));

    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}