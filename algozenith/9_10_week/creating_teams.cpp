#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

ll n,m;
ll vis[100100];
ll color[100100];
vector<ll> g[100100];
bool bipart = false;

void dfs(ll st, ll col)
{
    vis[st] = 1;
    color[st] = col;
    for(auto x: g[st])
    {
        if(vis[x]==0)
        {
            dfs(x,col^1);
        }
        else if(color[st] == color[x])
        {
            bipart = true;
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

    ll col = 0;
    for(ll i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            dfs(i,col);
        }
    }

    if(!bipart)
        cout << "YES\n";
    else
        cout << "NO\n"; 
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