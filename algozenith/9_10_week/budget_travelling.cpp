#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

#define MP make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,m;
vector<ii> g[10100];
ll dist[10100][100];
ll vis[10100][100];
ll cost[10110];
ll st,desti,tank;

void dijstra(ll st, ll fuels)
{
    for(ll i=0; i<=n; i++)
    {
        for(ll j=0; j<=tank; j++)
        {
            dist[i][j] = 1e18;
            vis[i][j] = 0;
        }
    }
    dist[st][fuels] = 0;
    priority_queue<pair<ll,ii>> pq;
    pq.push(MP(0,MP(st,fuels)));
    while(!pq.empty())
    {
        pair<ll,ii> temp = pq.top();
        pq.pop();
        ll node = temp.S.F;
        ll dists = -temp.F;
        ll fuel = temp.S.S;
        ll bug = cost[node];
        if(vis[node][fuel] == 1) continue;
        vis[node][fuel] = 1;
        if(tank>fuel)
        {
            if(dist[node][fuel+1] > dist[node][fuel]+bug)
            {
                dist[node][fuel+1] = dist[node][fuel]+bug;
                pq.push(MP(-dist[node][fuel+1],MP(node,fuel+1)));
            }
        }
        for(auto x : g[node])
        {
            // cout << "here\n";
            ll next = x.F;
            ll len = x.S;
            if(fuel>=x.S)
            {
                if(dist[next][fuel-len] > dist[node][fuel])
                {
                    dist[next][fuel-len] = dist[node][fuel];
                    pq.push(MP(-dist[next][fuel-len],MP(next,fuel-len)));
                }
            }    
        }
    }
}

void solve()
{
    cin >> n >> m;
    for(ll i=0; i<m; i++)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        g[a].push_back(MP(b,c));
        g[b].push_back(MP(a,c));
    }
    for(ll i=1; i<=n; i++)
    {
        cin >> cost[i];
    }
    cin >> st >> desti >> tank;
    dijstra(st,0);
    ll ans = 1e18;
    for(ll i=0; i<tank; i++)
    {
        ans = min(ans,dist[desti][i]);
    }
    // for(ll i=0; i<=n; i++)
    // {
    //     for(ll j=0; j<=tank; j++)
    //     {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans << '\n';
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