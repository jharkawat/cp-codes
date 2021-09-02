#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

ll dp[100100];
ll arr[100100];
ll n,k;

ll rec(ll level)
{
    // for(ll i=0;i<n;i++)
    // {
    //     cout << dp[i] ;
    // }
    // cout << "\n"; 
    if(level == n-1)
    {
        return 0;
    }
    if(dp[level]!= -1)
    {
        return dp[level];
    }
    ll ans = (abs(arr[level]-arr[level+1])+rec(level+1));
    for(ll i=2; i<=k; i++)
    {
        if(level<n-i)
        ans = min(ans,(abs(arr[level]-arr[level+i])+rec(level+i)));    
    }
    return dp[level]=ans;
}

void solve()
{
    cin >> n >> k;
    memset(dp,-1,sizeof(dp));
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << rec(0) << "\n";
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