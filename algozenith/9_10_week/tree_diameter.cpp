#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
vector<ll> tree[200100];
ll dist[200100];

void dfs(ll x, ll par)
{
    if(par==0)
    {
        dist[x] = 0;
    }
    else
    {
        dist[x]= dist[par]+1;
    }
    for(auto v : tree[x])
    {
        if(v != par)
        {
            dfs(v,x);
        }
    }
}


void solve()
{
    ll n; cin >> n;
    for(ll i=1; i<n; i++)
    {
        ll a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1,0);
    ll x;  
    ll maxi = -1;
    for(ll i=1; i<=n; i++)
    {
        if(dist[i]>maxi)
        {
            maxi = dist[i]; 
            x = i;
        }
        dist[i] = 0;
    }

    dfs(x,0);
    ll ans = -1;
    for(ll i=1; i<=n; i++)
    {
        ans = max(ans,dist[i]);
    }
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