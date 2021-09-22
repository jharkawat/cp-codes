#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define MP make_pair

/*
conditions
*/
ll n,m;
string mat[1010];

bool check(ll x, ll y)
{
    if(x>=n || x<0 || y>=m || y<0 || mat[x][y] == '#' || mat[x][y] == 'M') return 0;
    return 1;
}

void solve()
{
    cin >> n >> m;
    for(ll j=0; j<n; j++)
    {
        cin >> mat[j];
    }
    
    vector<ii> monst;
    vector<ii> ends;
    ii start;

    for(ll i=0; i<n; i++)
    {
        // cout << i << " end " << j << endl;
        for(ll j=0; j<m; j++)
        {
            if(mat[i][j] == 'M')
            {
                monst.push_back({i,j});
            }
            if((i==n-1 || j == m-1 || i ==0 || j == 0) && mat[i][j] == '.' )
            {
                ends.push_back({i,j});
            }
            if(mat[i][j] == 'A')
            {
                start = make_pair(i,j);
            }
        }
    }

    vector<vector<int>> distA(n,vector<int>(m,101010));
    vector<vector<int>> distM(n,vector<int>(m,101010));
    vector<vector<ii>> par(n,vector<ii>(m,MP(101010,101010)));

    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};

    queue<ii> A;
    A.push(start);
    distA[start.F][start.S] = 0;
    while(!A.empty())
    {
        ii ele = A.front();
        A.pop();
        int x = ele.F;
        int y = ele.S;

        for(int i=0; i<4; i++)
        {
            ll a = x + dx[i];
            ll b = y + dy[i];
            if(check(a,b) && distA[a][b] > distA[x][y] +1)
            {
                distA[a][b] = distA[x][y] +1;
                par[a][b] = MP(x,y);
                A.push(MP(a,b));
            }
        }
    }




    queue<ii> M;
    for(auto x: monst)
    {
        M.push(MP(x.F,x.S));
        distM[x.F][x.S] = 0;
    }
    while(!M.empty())
    {
        ii ele = M.front();
        M.pop();
        int x = ele.F;
        int y = ele.S;

        for(int i=0; i<4; i++)
        {
            ll a = x + dx[i];
            ll b = y + dy[i];
            if(check(a,b) && distM[a][b] > distM[x][y] +1)
            {
                distA[a][b] = distA[x][y] +1;
                A.push(MP(a,b));
            }
        }
    }

    vector<pair<int,ii>> pars;
    for(auto x: ends)
    {
        // cout << x.F << " " << x.S << endl;
        if(distA[x.F][x.S] < 101010)
        {
            pars.push_back(MP(distA[x.F][x.S],x));
        } 
    }

    bool nahi = true;
    sort(pars.begin(), pars.end());
    // cout << (int)pars.size() << endl;
    if((int)pars.size() == 0)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        // for(auto itr: pars)
        // {
        //     int dist = itr.F;
        //     if(dist<distM[itr.S.F][itr.S.S])
        //     {
        //         cout << "YES\n";
        //         cout << dist << endl;
        //         return;
        //     }
        // }
        
        for(auto itr: pars)
        {
            int dist = itr.F;
            int x = itr.S.F;
            int y = itr.S.S;
            while(x != start.F && y != start.S)
            {
                if(distA[x][y]>=distM[x][y])
                {
                    nahi = false;
                }
                ii temp = par[x][y];
                x = temp.F;
                y = temp.S;
            }
            if(nahi)
            {
                cout << "YES" << endl;
                cout << dist << endl;
                return;
            }
            else
            {
                nahi = true;
            }
        }
    }
    cout << "NO\n" << endl;
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