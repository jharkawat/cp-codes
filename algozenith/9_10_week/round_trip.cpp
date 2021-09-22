#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

ll n,m;
ll vis[100100];
vector<ll> g[100100];
bool cycle = false;

void dfs(ll st, ll par)
{
    // cout << "here\n";
    vis[st] = 1;
    for(auto x: g[st])
    {
        // cout << "here\n";
        // cout << st << " "<< x << endl; 
        if(vis[x]==0)
        {
            dfs(x,st);
        }
        else if(x != par)
        {
            cycle = true;
        }
    }
}


void solve()
{
    cin >> n >> m;
    for(ll i=0; i<m; i++)
    {
        ll a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(ll i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            dfs(i,0);
        }
    }
    if(cycle) cout << "YES\n";
    else cout << "NO\n";

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