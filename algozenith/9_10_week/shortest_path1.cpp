#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

#define F first
#define S second
#define MP make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n,m;
    cin >> n >> m;
    vector<ii> g[n+1];
    for(ll i=0; i<m ; i++)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        g[a].push_back({b,c});
    }

    ll dist[n+1];
    ll vis[n+1];
    for(ll i=0; i<=n; i++)
    {
        dist[i] = 1e18;
        vis[i] = 0;
    }
    dist[1]=0;
    priority_queue<ii> pq;
    pq.push(MP(-dist[1],1));
    while(!pq.empty())
    {
        ii temp = pq.top();
        pq.pop();
        ll len = -temp.F;
        ll node = temp.S;
        if(vis[node] != 0) continue;
        dist[node] = len;
        vis[node] = 1;
        for(auto x : g[node])
        {
            if(dist[x.F] > len + x.S)
            {
                dist[x.F] = len + x.S;
                pq.push(MP(-dist[x.F],x.F));
            }
        }
    }

    for(ll i=1; i<=n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << '\n';
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