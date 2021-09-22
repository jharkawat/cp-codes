#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

vector<ll> g[100100];
ll vis[100100];
ll tot;


void dfs(ll st)
{
    vis[st] =1;
    tot++;
    for(auto x:g[st])
    {
        if(vis[x] == 0)
        {
            dfs(x);
        }
    }
}

void solve()
{
    ll n,m;
    cin >> n >> m;
    for(ll i=0; i<m; i++)
    {
        ll a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<ll> ans;
    for(ll i=1; i<=n; i++)
    {
        if(vis[i] == 0)
        {
            tot = 0; 
            dfs(i);
            ans.push_back(tot);
        }
    }

    cout << (int)ans.size()-1 << '\n';
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