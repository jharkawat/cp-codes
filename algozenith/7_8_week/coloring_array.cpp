#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,m,k;
ll dp[110][110];
ll col[110][110];
ll arr[110];

ll rec(ll level, ll split)
{
    // base case
    if(level == 0)
    {
        if(split == -1)
        {
            return 0;
        }
        else
        {
            return 1e18;
        }
    }

    // cache
    if(dp[level][split] != -1)
    {
        return dp[level][split];
    }

    // logic
    ll ans = 1e18;
    for(ll i=level; i>0; i--)
    {
        if(arr[level] == )
    }

}


void solve()
{
    cin >> n >> m >> k;
    for(ll i=1; i<=n; i++)
    {
        cin >> arr[i];
    }
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=m ;j++)
        {
            cin >> col[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));

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