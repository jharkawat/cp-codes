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

struct unionfind{
    ll n, set_sz, *par, *rank;
    unionfind(){}
    unionfind(ll a)
    {
        n = set_sz = a;
        par = new ll[n+1];
        rank = new ll[n+1];
        for(ll i=0; i<=n; i++)
        {
            par[i]=i;
            rank[i]= 1;
        }
    }

    ll find(ll x)
    {
        if(par[x] != x)
        return par[x] = find(par[x]);
        return x;
    }

    void merge(ll x, ll y)
    {
        ll a = find(x);
        ll b = find(y);
        if(a != b)
        {
            if(rank[a] > rank[b])
            {
                par[b] = a;
                rank[a] += rank[b];
            }
            else
            {
                swap(a,b);
                par[b] = a;
                rank[a] += rank[b];
            }

        }
    }
};

void solve()
{
    ll N, R, c, r;
    cin >> N >> R >> c >> r;
    vector<pair<ll,ii>> cost_list;
    for(ll i=0; i<R; i++)
    {
        ll a,b;
        cin >> a >> b;
        cost_list.push_back(MP(r,MP(a,b)));
    }
    for(ll i=1; i<=N; i++)
    {
        cost_list.push_back(MP(c,MP(0,i)));
    }
    unionfind uf(N);
    ll cost = 0;
    sort(cost_list.begin(), cost_list.end());
    for(auto z: cost_list)
    {
        ll a = z.S.F;
        ll b = z.S.S;
        if(uf.find(a) != uf.find(b))
        {
            cost += z.F;
            uf.merge(a,b);
        }
    }
    cout << cost << endl;
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