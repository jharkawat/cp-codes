#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll const mod = 1e9+7;
ll n,m,k;
ll dp[202][202][404];
ll arr[202][202];

ll rec(int row, int col, int block)
{
    // pruning
    if(arr[row][col] == 1 && block == 0)
    {
        return 0;
    }

    // base case
    if(row == 0 && col == 0 )
    {
        // cout << "here" << endl;

        return 1;
    }
    // cout << "here" << endl;

    // cache
    if(dp[row][col][block] != -1)
    {

        return dp[row][col][block];
    }
    // cout << "here" << endl;

    // logic
    ll ans = 0;
    if(arr[row][col] == 0)
    {
        if(row > 0)
        {
            ans += rec(row-1,col,block);
        }
        if(col > 0 )
        {
            ans += rec(row,col-1,block);
        }
    }
    else if(arr[row][col] == 1)
    {
        if(row > 0)
        {
            ans += rec(row-1,col,block-1);
        }
        if(col > 0 )
        {
            ans += rec(row,col-1,block-1);
        }
    }

    // cout << row << " " << col << " " << block << " " << ans << endl;

    // save and return 
    return dp[row][col][block] = ans%mod;
}

void solve()
{
    cin >> n >> m >> k;
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            cin >> arr[i][j];
        }
    }
    // for(ll i=0; i<n; i++)
    // {
    //     for(ll j=0; j<m; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            for(ll a=0; a<=k; a++)
            {
                dp[i][j][a] = -1;
            }
        }
    }


    // cout << "here" << endl;
    cout << rec(n-1,m-1,k) << endl;
    // cout << "here" << endl;

    // for(ll i=0; i<=k; i++)
    // {
    //     for(ll j=0; j<n; j++)
    //     {
    //         for(ll a=0; a<m; a++)
    //         {
    //             cout << rec(j,a,i) << " ";  
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    //     cout << endl;
    // }
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