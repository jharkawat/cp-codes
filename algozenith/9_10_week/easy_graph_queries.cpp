#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
vector<ll> g[100100];
ll vis[100100];
ll col[100100];
ll siz[100100];
ll total;

void dfs(ll st, ll color)
{
    vis[st] = 1;
    col[st] = color;
    total++;
    for(auto x: g[st])
    {
        if(vis[x]==0)
        {
            dfs(x,color);
        }
    }
}

void solve()
{
    ll n,m,q;
    cin >> n >> m >> q;
    for(ll i=0; i<m; i++)
    {
        ll a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ll color = 0; 
    for(ll i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            total = 0; 
            dfs(i,color);
            siz[color]=total;
        }
        color++;
    }

    for(ll i=0; i<q; i++)
    {
        ll no; cin >> no;
        if(no ==1)
        {
            ll x;
            cin >> x;
            cout << siz[col[x]] << endl;
        }
        else
        {
            ll x,y;
            cin >> x >> y;
            if(col[x]==col[y])
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
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