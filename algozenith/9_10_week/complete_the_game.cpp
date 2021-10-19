#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,m;
vector<ll> g[200100];
ll dp[200100];
ll const mod = 1e9+7;
ll vis[200200];

ll dfs(ll node, ll par)
{
    // cout << "node " << node << "par: " << par << endl;
    if(node == n)
    {
        return 1;
    }
    if(dp[node] != -1) return dp[node];
    ll ans =0;
    // vis[node] = 1;
    for(auto x: g[node])
    {
        if(x != par && vis[x] == 0)
        {
            ans += dfs(x,node);
            ans = ans%mod;
        }
    }
    // vis[node] = 0;
    return dp[node] = ans;
}

void solve()
{ 
    cin >>n >> m;
    for(ll i=0; i<m; i++)
    {
        ll a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(dp,-1,sizeof(dp));
    
    cout << dfs(1,0) << endl;
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