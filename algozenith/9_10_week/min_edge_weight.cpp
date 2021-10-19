#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

struct unionfind{
    ll n; 
    ll *rank, *par;
    unionfind(ll N)
    {
        n = N;
        rank = new ll[n+1];
        par = new ll[n+1];
        for(ll i=0; i<=n; i++)
        {
            par[i]=i;
            rank[i]=1;
        }
    }

    ll find(ll x)
    {
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    ll merge(ll x, ll y)
    {
        ll xroot = find(x);
        ll yroot = find(y);
        if(xroot != yroot)
        {
            ll ans = rank[xroot]*rank[yroot];
            if(rank[xroot] > rank[yroot])
            {
                par[yroot] = xroot;
                rank[xroot] += rank[yroot]; 
            }
            else
            {
                par[xroot] = yroot;
                rank[yroot] += rank[xroot]; 
            }
            return ans;
        }
    }
};

void solve()
{ 
    ll n; cin >> n;
    vector<pair<ll,pair<ll,ll>>> edges;
    for(ll i=1; i<n; i++)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        edges.push_back(make_pair(c,make_pair(a,b)));
    }
    sort(edges.begin(),edges.end(),greater<pair<ll,pair<ll,ll>>>());
    ll ans = 0;
    unionfind ut(n);
    for(auto x: edges)
    {
        ll cost = x.first;
        ll a = x.second.first;
        ll b = x.second.second;
        ans += cost*(ut.merge(a,b));
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

    // solve();

    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}