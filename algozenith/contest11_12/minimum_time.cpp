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
char mat[1010][1010];
ll dist[1010][1010];

bool check(ll x, ll y)
{
    if(x<0 || x>=n || y<0 || y>=m || mat[x][y] == '#') return 0;
    return 1;
}

void solve()
{
    cin >> n >> m;
    for(ll i=0; i<n; i++)    
    {
        for(ll j=0; j<m; j++)
        {
            cin >> mat[i][j];
        }
    }
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll dx[] = {1,1,1,0,0,-1,-1,-1};
    ll dy[] = {1,0,-1,1,-1,1,0,-1};
    for(ll i=0; i<n; i++)    
    {
        for(ll j=0; j<m; j++)
        {
            dist[i][j] = 1e18;
        }
    }
    queue<ii> qu;
    dist[a][b] = 0;
    qu.push(MP(a,b));
    while(!qu.empty())
    {
        ii temp = qu.front();
        qu.pop();
        ll x = temp.F;
        ll y = temp.S;
        for(ll k=0; k<8; k++)
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
    if(dist[c][d] == 1e18) cout << "-1\n";
    else cout << dist[c][d] << endl;
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