#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

struct unionfind
{
    vector<ll> par,rank;
    ll n; 

    unionfind(int N)
    {
        n = N;
        for(ll i=0; i<=n; i++)
        {
            par.push_back(i);
            rank.push_back(1);
        }
    }

    ll find(int x)
    {
        if(x==par[x]) return x;
        else return par[x] = find(par[x]);
    }

    void merge(ll x, ll y)
    {
        ll x_root = find(x);
        ll y_root = find(y);
        if(x_root != y_root)
        {
            if(rank[x_root] > rank[y_root])
            {
                par[y_root] = x_root;
                rank[x_root] += rank[y_root];
            }
            else
            {
                par[x_root] = y_root;
                rank[y_root] += rank[x_root];

            }
        }
    }
};

void solve()
{ 
    ll n,q;
    cin >> n >> q;
    unionfind ui(n);
    while(q--)
    {
        int type;
        cin >> type;
        ll l,r;
        cin >> l >> r;
        // cout << type << " " << l << " " << r << endl;
        if(type==0)
        {
            ui.merge(l,r);
        }
        else
        {
            if(ui.find(l) == ui.find(r)) cout << "1\n";
            else cout << "0\n";
        }
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