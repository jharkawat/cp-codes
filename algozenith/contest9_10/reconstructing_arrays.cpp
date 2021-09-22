#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,m,totalcost; 
ll dp[101][101][101][2];

ll const mod = 1e9+7;

ll rec(ll level, ll num, ll cost, ll pos)
{
    // pruning
    if(num==m && cost != 0)
    {
        return 0;
    }

    // base case
    if(level == n)
    {
        return (cost == 0)?1:0;
    }

    // cache
    if(dp[level][num][cost][pos] != -1)
    {
        return dp[level][num][cost][pos];
    }

    // logic
    ll ans = 0;
    if(cost == 0)
    {
        ans += num*rec(level+1,num,cost,0);
    }
    else
    {
        ans += m*rec(level+1,num,cost,pos);
        ans += rec(level+1,num+1,cost-1,0);
        ans += rec(level,num+1,cost,1);
    }
    ans = ans%mod;

    // save and return 
    return dp[level][num][cost] = ans;
}


void solve()
{
    cin >> n >> m >> totalcost;
    memset(dp,-1,sizeof(dp));
    cout << rec(0,1,totalcost) << '\n';
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