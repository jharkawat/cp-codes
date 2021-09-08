#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,k;
ll dp[2020][1010][2];

ll const mod = 1000000007;

ll rec(ll level, ll open_bracket, ll done)
{
    // pruning

    // base case
    if(level == n)
    {
        if(open_bracket == 0 && done == 1)
        {
            return 1;
        }
        else
        return 0; 
    }

    // cache
    if(dp[level][open_bracket][done] != -1)
    {
        return dp[level][open_bracket][done];
    }

    // logic
    ll ans = 0;
    if(open_bracket == 0)
    {
        ans = rec(level+1, open_bracket+1, done);
    }
    else if( (n-level)>open_bracket && k > open_bracket) 
    {
        ans = rec(level+1, open_bracket+1, done) + rec(level+1, open_bracket-1, done);
    }
    else if(open_bracket == k)
    {
        ans = rec(level+1, open_bracket-1, 1);
    }
    else
    {
        ans = rec(level+1, open_bracket-1, done);
    }

    // save and return 
    ans = ans%mod;
    return dp[level][open_bracket][done] = ans;
}

void solve()
{
    cin >> n >> k;
    memset(dp,-1,sizeof(dp));
    cout << rec(0,0,0) << '\n';
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    solve();

    // ll t; cin >> t; 
    // while(t--)
    // {
    //     solve();
    // }
}