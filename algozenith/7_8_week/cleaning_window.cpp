#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,m;
ll dp[1010][1010];
ll timess[1010][1010];

ll rec(ll row, ll col)
{
    // base case
    if(row == 0)
    {
        return timess[row][col];
    }

    // cache
    if(dp[row][col] != -1)
    {
        return dp[row][col];
    }

    // logic
    ll ans = timess[row][col];
    if(m==1)
    {
        ans = max({ans, rec(row-1,col)});
    }
    else if(col == 0)
    {
        ans = max({ans, rec(row-1,col), rec(row-1,col+1)});
    }
    else if(col == m-1)
    {
        ans = max({ans, rec(row-1,col), rec(row-1,col-1)});
    }
    else
    {
        ans = max({ans, rec(row-1,col), rec(row-1,col-1), rec(row-1,col+1)});
    }

    // save and return 

    return dp[row][col] = ans;
}

void solve()
{
    cin >> n >> m;
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            cin >> timess[i][j];
        }
    }
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            dp[i][j] = -1;     
        }
    }
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            cout << (rec(i,j) <= timess[i][j]);
        }
        cout << '\n';
    }


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