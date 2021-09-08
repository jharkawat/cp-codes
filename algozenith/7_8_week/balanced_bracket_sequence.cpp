#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
string str;
ll n;
ll dp[1010][1010];

ll const mod = 1e9+7;

ll rec(ll level, ll depth)
{
    // pruning
    if(depth<0)
    {
        return 0;
    }

    // base case
    if(level == n)
    {
        if(depth == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // memory check
    if(dp[level][depth] != -1)
    {
        return dp[level][depth];
    }

    // logic
    ll ans = 0; 
    if(str[level] == '?')
    {
        if(depth > 0) 
        {
            ans += rec(level+1,depth-1);
        }
        ans += rec(level+1, depth+1);
    }
    else if(str[level] == '(')
    {
        ans = rec(level+1,depth+1);
    }
    else
    {
        ans = rec(level+1,depth-1);
    }

    // save and return 
    return dp[level][depth] = ans%mod;
}



void solve()
{
    cin >> str;
    n = str.size();
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << rec(0,0) << "\n";
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