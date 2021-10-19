#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n;
vector<ll> g[200100];
ll dist[200100];
ll subtree[200100];
ll par[200100];

void dfs(ll node, ll parent, ll depth)
{
    par[node] = parent;
    dist[node] = depth;
    subtree[node] = 1;
    for(auto x : g[node])
    {
        if(x != parent)
        {
            dfs(x,node,depth+1);
            subtree[node] += subtree[x];
        }
    }
}

void solve()
{ 
    cin >> n;
    for(ll i=1; i<n; i++)
    {
        ll a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,1,0);
    ll ans = 0;
    for(ll i=1; i<=n; i++)
    {
        ans += subtree[i]*(n-subtree[i]);
    }
    cout << ans << endl;
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