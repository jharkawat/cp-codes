#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,ii>> g;
    for(ll i=0; i<m ; i++)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        g.push_back({-c,{a,b}});
    }

    ll dist[n+1];
    for(ll i=1; i<=n; i++)
    {
        dist[i] = 1e18;
    }
    dist[1] = 0;
    for(ll i=0; i<n-1; i++)
    {
        for(auto v : g)
        {
            ll cost = v.F;
            ll x = v.S.F;
            ll y = v.S.S;
            if(dist[y] > dist[x]+cost)
            {
                dist[y] = dist[x]+cost;
            }
        }
    }
    bool cycle = false;
    for(auto v : g)
    {
        ll cost = v.F;
        ll x = v.S.F;
        ll y = v.S.S;
        if(dist[y] > dist[x]+cost)
        {
            cycle = true;
        }
    }

    if(cycle)
    {
        cout << "-1\n";
    }
    else
    {
        cout << -dist[n] << "\n";
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