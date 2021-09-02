#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

ll dp[100100][3];
ll mat[100100][3];
ll n;

ll rec(ll level, ll pos)
{
    if(level == n)
    {
        return 0;
    }
    if(dp[level][pos] != -1)
    {
        return dp[level][pos];
    }
    ll ans = 0;
    for(int i=0; i<3; i++)
    {
        if(i!=pos)
        {
            ans = max(ans,mat[level][i]+rec(level+1,i));
        }
    }
    // for(ll i=0; i<n; i++)
    // {
    //     for(int j=0; j<3; j++)
    //     {
    //         cout << dp[i][j] << " "; 
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    return dp[level][pos] = ans;
}

void solve()
{
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(ll i=0; i<n; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin >> mat[i][j];
        }
    }
    ll ans = 0;
    for(int i=0; i<3; i++)
    {
        ans = max(ans,mat[0][i]+rec(1,i));
    }
    cout << ans << "\n";
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    
    solve();
}