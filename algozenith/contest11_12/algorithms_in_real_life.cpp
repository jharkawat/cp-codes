#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
using pii = pair<ll,ii>;

#define MP make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll m,h,n,k;
vector<ii> edges[1010];
ll pathlen[1010];
ll dist[1010];
ll vis[1010];

void dijstra(ll st)
{
    for(ll i=0; i<=m; i++)
    {
        dist[i] = 1e18;
        pathlen[i] = 0;
        vis[i]=1e18;
    }
    dist[1] = 0;
    pathlen[1] = 0;
    priority_queue<ii> pq;
    pq.push(MP(-0,1));


    while(!pq.empty())
    {
        ii temp = pq.top();
        pq.pop();
        ll len = -temp.F;
        ll node = temp.S;
        if(pathlen[node] > vis[node]) continue;
        vis[node] = pathlen[node];
        for(auto x : edges[node])
        {
            ll to = x.F;
            ll cost = x.S;
            if(dist[to] > dist[node] + cost)
            {
                dist[to] = dist[node] + cost;
                pathlen[to] = pathlen[node] + 1;
                pq.push(MP(-dist[to],to));
            }
            else if((dist[to] = dist[node] + cost) && pathlen[to] > pathlen[node] + 1) 
            {
                dist[to] = dist[node] + cost;
                pathlen[to] = pathlen[node] + 1;
                pq.push(MP(-dist[to],to));
            }
        }
    }
}

void solve()
{
    cin >> m >> h >> n;
    for(ll i=1; i<=n; i++)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    cin >> k;
    dijstra(1);
    if(dist[h]==1e18 || pathlen[h]>k) cout << "-1\n";
    else cout << dist[h] << endl;
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