#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n;
string mat[1010];

bool check(ll i, ll j)
{
    if(i>=n || i<0 || j>=n || j<0)return 0;
    if(mat[i][j]=='.') return 0;
    return 1;
}

bool comp(ii &a, ii &b)
{
    if(a.first == b.first)
    {
        return a.second < b.second;
    }

    return a.first > b.first;
}

ll dx[] = {1,0,-1,0};
ll dy[] = {0,1,0,-1};

vector<ii> dim;
ll vis[1010][1010];
ll area = 0;
ll peri = 0;

void dfs(ll i, ll j)
{
    vis[i][j] = 1; 
    area++;
    for(ll k=0; k<4; k++)
    {
        ll a = i+dx[k]; 
        ll b = j+dy[k];
        if(check(a,b) && (vis[a][b] == 0))
        {
            dfs(a,b);
        }
        else
        {
            if(a>=n || a<0 || b>=n || b<0) peri++;
            // if(a<n && a>=0 && b<n && b>=0)
            else if(mat[a][b] == '.') peri++;
        }
    }   
}


void solve()
{
    cin >> n;
    for(ll i=0 ; i<n ; i++) 
    {
        cin >> mat[i];
    }

    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
        {
            if(check(i,j) && (vis[i][j] == 0))
            {
                area = 0;
                peri =0;
                dfs(i,j);
                dim.push_back({area,peri});
            }
        }
    }

    sort(dim.begin(), dim.end(), comp);

    auto x = dim.begin();
    cout << x->first << " " << x->second << endl;
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