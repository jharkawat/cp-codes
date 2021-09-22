#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,m;
string arr[1010];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool check(int x, int y)
{
    if(x<0 || x>=n || y<0 || y>=m || arr[x][y] == '#') return 0;
    return 1; 
}

ll vis[1010][1010];

void dfs(int x, int y)
{
    vis[x][y] =1;
    for(int i=0; i<4; i++)
    {
        ll a,b;
        a = x + dx[i];
        b = y + dy[i];
        if(check(a,b) && (vis[a][b] == 0))
        {
            dfs(a,b);
        }
    }
}

void solve()
{
    cin >> n >> m;
    for(ll i=0; i<n; i++){
        cin >> arr[i];
    }

    ll count = 0;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++)
        {
            if(check(i,j) && (vis[i][j] == 0))
            {
                count++;
                // cout << i << " " << j << endl;
                dfs(i,j);
            }
        }
    }
    cout << count << endl;
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