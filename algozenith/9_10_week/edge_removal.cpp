#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct unionfind{
    ll n,size;
    ll *rank, *par;
    unionfind(ll N)
    {
        n = size = N;
        rank = new ll[n+1];
        par = new ll[n+1]; 
        for(ll i =0; i<=n; i++)
        {
            rank[i] = 1;
            par[i] = i;
        }
    }
    
    ll find(ll x)
    {
        if(x = par[x]) return x;
        else return par[x]= find(par[x]);
    }
    
    void merge(ll x, ll y)
    {
        ll xroot = find(x);
        ll yroot = find(y);
        if(xroot != yroot)
        {
            size--;
            if(rank[xroot]>rank[yroot])
            {
                par[yroot] = xroot;
                rank[xroot] += rank[yroot];
            }
            else
            {
                par[xroot] = yroot;
                rank[yroot] += rank[xroot];
            }
        }
    }
    
    ll ele()
    {
    	return size;
    }
};

signed main()
{

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    
    ll n,m,q;
    cin >> n >> m >> q;
    vector<pair<ll,ll>> edges(m+1),query;
    bool visit[m+1];
    for(int i=1; i<=m; i++)
    {
        ll a,b;
        cin >> a >> b;
        visit[i]=true;
        edges[i] = make_pair(a,b);
    }
    for(ll i=0; i<q; i++)
    {
        ll que;
        cin >> que;
        if(que == 2)
        {
            query.push_back({2,-1});
        }
        else
        {
            ll p;cin >> p;
            query.push_back({1,p});
            visit[p] = false;
        }
    }
    reverse(query.begin(),query.end());
    unionfind ut(n);
    for(ll i=1; i<=m; i++)
    {
        // cout << ut.ele() << endl;

        if(visit[i])
        {
            ll a = edges[i].first;
            ll b = edges[i].second;
            ut.merge(a,b);
        }
    }
    // cout << ut.ele() << endl;
    vector<ll> ans;
    for(ll i=0; i<q; i++)
    {
        ll a = query[i].first;
        ll b = query[i].second;
        // cout << "a: " << a << " b: " << b << endl;
        if(a==2)
        {
            ans.push_back(ut.ele());
        }
        else
        {
            ll x = edges[b].first;
            ll y = edges[b].second;
            // cout << "x: " << x << " y: " << y << endl;
            // cout << ut.find(x) << " " << ut.find(y) << endl;
            ut.merge(x,y);            
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto x: ans)
    {
        cout << x <<  endl;
    }
}