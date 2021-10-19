#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
vector<ll> g[200100];
ll n; 
ll dist[200100];
int parent[200100];

void dfs(ll node, ll par)
{
    if(par==0)
    {
        dist[node] =0;
    }
    else
    {
        dist[node] = 1+dist[par];
    }
    parent[node] = par; 
    for(auto x: g[node])
    {
        if(x != par)
        {
            dfs(x,node);
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
    if(n==1)
    {
        cout << "1\n";
        return ;
    }
    dfs(1,0);
    ll x; ll maxi = 0;
    for(ll i=1; i<=n; i++)
    {
        if(dist[i]>maxi)
        {
            maxi = dist[i];
            x = i;
        }
        dist[i]=0;
    }
    dfs(x,0);
    maxi = 0;
    for(ll i=1; i<=n; i++)
    {
        if(dist[i]>maxi)
        {
            maxi = dist[i];
            x = i;
        }
        dist[i]=0;
    }
    if(maxi%2 == 0)
    {
        ll dia = maxi/2;
        while(dia--)
        {
            x = parent[x];
        }
        cout << x << endl;
    }
    else cout << "-1\n";
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