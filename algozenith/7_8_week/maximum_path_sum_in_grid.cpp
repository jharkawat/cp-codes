#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll h,w;
ll arr[1010][1010];
ll dp[1010][1010];


ll rec(ll row, ll col)
{
    if(row == h-1 && col == w-1)
    {
        return arr[row][col];
    }
    if(dp[row][col] != -1)
    {
        return dp[row][col];
    }
    ll ans =0;
    if(row < h-1)
    {
        ans = max(ans,arr[row][col]+rec(row+1,col));
    }
    if(col < w-1)
    {
        ans = max(ans,arr[row][col]+rec(row,col+1));
    }
    return dp[row][col] = ans;
}

void solve()
{
    cin >> h >> w;
    for(ll i=0; i<h; i++)
    {
        for(ll j=0; j<w; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(ll i=0; i<h; i++)
    {
        for(ll j=0; j<w; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << rec(0,0) << "\n";
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    
    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}