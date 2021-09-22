#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
vector<int> g[200100];
int dist[200100];
int parent[200100];
int dia;

void dfs(int st, int par)
{
    if(par==0)
    {
        dist[st] = 0;
    }
    else
    {
        dist[st] = dist[par] + 1;
    }
    parent[st] = par;
    for(auto v: g[st])
    {
        if(v != par)
        {
            dfs(v,st);
        }
    }
}

int tot =0;
int subdist[200100];
void dfs2(int st, int par)
{
    // cout << "st: " << st << " par: " << par << endl;
    subdist[st] = subdist[par] + 1;
    if(subdist[st] == dia) 
    {
        // cout << st << " here\n";
        tot++;
    }
    for(auto v: g[st])
    {
        if(v != par)
        {
            dfs2(v,st);
        }
    }
}

void solve()
{
    int n; cin >> n;
    for(int i=1; i<n; i++)
    {
        int a ,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    int maxi = -1;
    int x; 
    for(int i=1; i<=n; i++)
    {
        if(dist[i] > maxi)
        {
            maxi = dist[i];
            x = i; 
        }
        dist[i]=0;
    }

    dfs(x,0);
    maxi = -1;
    x; 
    for(int i=1; i<=n; i++)
    {
        if(dist[i] > maxi)
        {
            maxi = dist[i];
            x = i; 
        }
        dist[i]=0;
    }

    // cout << maxi << x << endl;

    if(maxi%2 == 0)
    {
        dia = maxi/2;
        int node;
        for(int i=1; i<=dia; i++)
        {
            node = parent[x];
            x = parent[x];
        }
        // cout << dia << " " << node << endl;
        subdist[node] = 0;
        vector<int> siz; 
        for(auto a : g[node])
        {
            tot = 0; 
            dfs2(a,node);
            siz.push_back(tot);
        }
        int finals = 0, temp =0;
        // for(int i=1; i<=n; i++)
        // {
        //     cout << subdist[i] << endl;
        // }
        for(auto a : siz)
        {
            // cout << a << endl;
            finals += a*temp;
            temp += a;
        }
        cout << finals << "\n";
    }
    else
    {
        dia = maxi/2;
        int node1, node2;
        for(int i=1; i<=dia+1; i++)
        {
            // cout << x << endl;
            if(i == dia)
            {
                node1 = parent[x];
            }
            else if(i == dia+1)
            {
                node2 = parent[x];
            }
            x = parent[x];
        }
        // cout << dia << " " << node1 << " " << node2 << endl;
        subdist[node1] = -1;
        subdist[node2] = -1;
        int s1,s2;
        tot = 0;
        dfs2(node1,node2);
        s1 = tot;
        subdist[node1] = -1;
        subdist[node2] = -1;
        tot = 0;
        dfs2(node2,node1);
        s2 = tot;
        cout << s1*s2 << '\n';
        // for(auto a : g[node])
        // {
        //     if(a != node2)
        //     tot = 0; 
        //     dfs2(a,node);
        //     siz.push_back(tot);
        // }
        // int finals = 0, temp =0;
        // for(auto a : siz)
        // {
        //     finals += a*temp;
        //     temp += a;
        // }
        // cout << finals << "\n";

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