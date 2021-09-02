#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

ll dp[101][100100];
ll n,w;
ll weight[101], value[101];

ll rec(ll level, ll W)
{
    if(level == n)
    {
        return 0;
    }
    if(dp[level][W] != -1)
    {
        return dp[level][W];
    }
    ll ans = rec(level+1,W);
    if(weight[level]<=W)
    {
        ans = max(ans,value[level]+rec(level+1,W-weight[level]));
    }
    return dp[level][W] = ans;
}

void solve()
{
    cin >> n >> w;
    memset(dp,-1,sizeof(dp));
    for(ll i=0; i<n; i++)
    {
        cin >> weight[i];
        cin >> value[i];
    }
    cout << rec(0,w) << endl;
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