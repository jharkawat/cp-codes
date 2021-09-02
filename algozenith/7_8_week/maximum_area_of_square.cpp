#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

int arr[1010][1010];
int dp[1010][1010];
ll n,m;

ll rec(ll row, ll col)
{
    if(row ==0 && col==0)
    {
        if(arr[row][col] == 1)
        return 1;
        else 
        return 0;
    }
    if(dp[row][col] != -1)
    {
        return dp[row][col];
    }
    ll ans = 0;
    if(arr[row][col] == 1)
    {
        if(row==0 || col==0)
        {
            ans = 1;
        }
        else
        {
            ans = 1 + min(rec(row-1,col-1),min(rec(row-1,col),rec(row,col-1)));
        }
    }
    return dp[row][col] = ans;
}


void solve()
{
    cin >> n >> m;
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(ll i=0; i<=n; i++)
    {
        for(ll j=0; j<=m; j++)
        {
            dp[i][j] = -1;
        }
    }
    rec(n,m);
    ll tot=0;
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            // cout << dp[i][j] << " ";
            ll area = rec(i,j)*rec(i,j);
            tot = max(tot, area);
        }
        // cout << endl;
    }
    cout << tot << "\n";
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