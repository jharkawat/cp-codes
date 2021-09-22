#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,k,m;
string str[101];
vector<ll> siz;
ll vis[101][11];
ll col[101][11];
ll counts = 0;
ll color = 0;

ll dx[] = {1,0,-1,0};
ll dy[] = {0,1,0,-1};

bool check(ll x,ll y)
{
    if(x<0 || x>=n || y<0 || y>=m || str[x][y] == '0') 
    {
        // cout << x << " " << y << endl;
        // cout << n << " " << m << endl;        
        // cout << "in here\n";
        return 0;
    }    
    return 1;
}

void dfs(ll x, ll y, ll color)
{
    // cout << "in dfs\n";
    vis[x][y] = 1;
    col[x][y] = color;
    counts++;
    for(int i=0; i<4; i++)
    {
        ll a = x+dx[i];
        ll b = y+dy[i];
        if(check(a,b) && (vis[a][b] == 0) && str[x][y]==str[a][b])
        {
            dfs(a,b,color);
        }
    }
}

void gravity()
{
    // cout << "ingravity\n";
    for(ll i=0; i<m; i++)
    {
        ll total = 0;
        for(ll j=n-1; j>=0; j--)
        {
            // char ch = str[][]
            if(str[j][i] == '0')
            {
                // cout << str[j][i] << endl;
                total++;
            }
            else
            {
                str[j+total][i] = str[j][i]; 
                if(total != 0) str[j][i] = '0';
            }
        }
    }
}

void solve()
{
    cin >> n >> k;
    for(ll i=0; i<n; i++)
    {
        cin >> str[i];
    }
    m = 10;
    ll flag = 0;
    while(1)
    {
        // cout << "here\n";
        bool exits = true;
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=m; j++)
            {
                vis[i][j] = 0;
                col[i][j] = 0;
            }
        }
        color =0;
        siz.clear();
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                // cout << "hereall\n";
                // cout << str[i][j] << endl;
                // cout << check(i,j) << " " <<vis[i][j];
                if(check(i,j) && (vis[i][j] == 0))
                {
                    counts=0;
                    dfs(i,j,color);
                    siz.push_back(counts);
                    color++;
                }
            }
        }
        // cout << "here2\n";
        // for(auto x:siz)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        for(ll i=0; i<siz.size(); i++)
        {
            if(siz[i]>=k)
            {
                // cout << "heress\n" ;
                exits = false;
                for(ll l=0; l<=n; l++)
                {
                    for(ll j=0; j<=m; j++)
                    {
                        if(col[l][j] == i)
                        {
                            str[l][j] = '0';
                        }
                    }
                }
            }
        }
        // cout << "here3\n";

        gravity();
        // cout << "here4\n";

        if(exits)
        {
            // cout << "here\n";
            break;
        }
        // flag++;
        // if(flag == 6)
        // {
        //     break;
        // }
        // for(ll i=0; i<n; i++)
        // {
        //     for(ll j=0; j<m; j++)
        //     {
        //         cout << str[i][j] ;
        //     }
        //     cout << endl;
        // }

    }
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            cout << str[i][j] ;
        }
        cout << endl;
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