#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// using ii = pair<ll,ll>;

// #define MP make_pair
// #define F first
// #define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,m,q;
int mat[1010][1010];
int vis[1010][1010];
int color[1010][1010];

ll counts = 0;

bool check(ll x, ll y)
{
    if(x<=0 || x>n || y<=0 || y>m || mat[x][y] == 0) return 0;
    return 1; 
}

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void dfs(ll stx, ll sty, ll col)
{
    vis[stx][sty] = 1;
    color[stx][sty] = col;
    counts++;
    for(int i=0; i<4; i++)
    {
        ll a = stx + dx[i];
        ll b = sty + dy[i];
        if(check(a,b) && (vis[a][b] == 0))
        {
            dfs(a,b,col);
        }
    }
}

void solve()
{
    cin >> n >> m >> q;
    ll total = 0;
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=m; j++)
        {
            cin >> mat[i][j];
            if(mat[i][j] == 1) total++;
        }
    }
    map<ll,ll> mpp;
    ll col = 1;
    mpp[0] = 0;
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=m; j++)
        {
            if(check(i,j) && (vis[i][j] == 0))
            {
                counts = 0;
                dfs(i,j,col);
                mpp[col] = counts;
                col++;
            }
        }
    }
    while(q--)
    {
        ll a,b;
        cin >> a >> b;
        ll t = color[a][b];
        total -= mpp[t];
        mpp[t] = 0;
        cout << total << '\n';
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