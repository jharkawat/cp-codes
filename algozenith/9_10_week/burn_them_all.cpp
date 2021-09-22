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
    for(ll i=0; i<m; i++)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        g[a].push_back(MP(b,c));
        g[b].push_back(MP(a,c));
    }
    ll st; 
    cin >> st;
    ll dist[n+1];
    bool vis[n+1];
    for(ll i=1; i<=n; i++)
    {
        dist[i] = 1e18;
        vis[i] = false;
    }
    dist[st] = 0;
    priority_queue<ii> pq;
    pq.push(MP(0,st));
    while(!pq.empty())
    {
        ii temp = pq.top();
        pq.pop();
        ll dists = -temp.F;
        ll node = temp.S;
        if(vis[node]==true) continue;
        dist[node] = dists;
        vis[node] = true;
        for(auto x: g[node])
        {
            ll out = x.F;
            ll cost = x.S;
            if(dist[out] > dist[node]+cost)
            {
                dist[out] = dist[node]+cost;
                pq.push(MP(-dist[out],out));
            }
        }
    }

    ll ans = -1e18;
    for(ll i=1; i<=n; i++)
    {
        // ans = max(ans,(ll)dist[i]);
        for(auto v : g[i])
        {
            ll temp = ((ll)dist[v.F] + (ll)v.S + (ll)dist[i])*5;
            ans = max(ans,temp);
        }
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