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

struct unionfind{
    ll n, components, *parent, *rank;
    unionfind(){};
    unionfind(ll a)
    {
        n = components = a;
        parent = new ll[n+1];
        rank = new ll[n+1];
        for(ll i=1; i<=n; i++)
        {
            parent[i] = i;
            rank[i]=1;
        }
    }
    ll find(ll x)
    {
        if(parent[x]!=x) return parent[x] = find(parent[x]);
        return x;
    }

    void merge(ll x, ll y)
    {
        ll a = find(x);
        ll b = find(y);
        if(a != b)
        {
            if(rank[a] >= rank[b])
            {
                parent[b] = a;
                rank[a] += rank[b];
            }
            else
            {
                parent[a] = b;
                rank[b] += rank[a];
            }
            components--;
        }
    }
};

void solve()
{
    vector<pair<ll,ii>> edgelist;
    ll n,m; cin >> n >> m;
    unionfind ut(n);
    for(ll i=0; i<m; i++)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        edgelist.push_back({c,{a,b}});
    }
    sort(edgelist.begin(), edgelist.end());
    ll cnt = 0; 
    ll mst = 0;
    for(auto v: edgelist)
    {
        ll x = v.S.F;
        ll y = v.S.S;
        if( ut.find(x) != ut.find(y) )
        {
            cnt++;
            mst += v.F;
            ut.merge(x,y);
        }
    }
    if(cnt != (n-1))
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << mst << '\n';
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