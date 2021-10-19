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
ll n,m;
ll mat[1550][1550];
ll dist[1550][1550];

bool check(ll x, ll y)
{
    if(x<=0 || x>n || y<=0 || y>m) return 0;
    return 1;
}

void solve()
{
    cin >> n >> m;
    for(ll i=1; i<=n; i++)    
    {
        for(ll j=1; j<=m; j++)
        {
            cin >> mat[i][j];
        }
    }

    for(ll i=1; i<=n; i++)    
    {
        for(ll j=1; j<=m; j++)
        {
            dist[i][j] = 1e18;
        }
    }
    queue<ii> qu;
    dist[1][1] = 0;
    qu.push(MP(1,1));
    while(!qu.empty())
    {
        ii temp = qu.front();
        qu.pop();
        ll x = temp.F;
        ll y = temp.S;
        ll dx[] = {mat[x][y],0};
        ll dy[] = {0,mat[x][y]};

        for(ll k=0; k<2; k++)
        {
            ll i = x + dx[k];
            ll j = y + dy[k];
            if(check(i,j) && dist[i][j] > dist[x][y] + 1)
            {
                dist[i][j] = dist[x][y] + 1;
                qu.push(MP(i,j));
            }
        }

    }
    if(dist[n][m] == 1e18) cout << "-1\n";
    else cout << dist[n][m] << endl;
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