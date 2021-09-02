#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n;
ll arr[505];
ll prefix[505];
ll dp[505][505];

ll rec(ll l, ll r)
{
    // pruning
    if(l==r)
    {
        return 0;
    }

    // basecase
    if(l==r-1)
    {
        return arr[l]*arr[r];
    }

    // cache
    if(dp[l][r] != -1)
    {
        return dp[l][r];
    }

    // logic
    ll ans = 1e18; 
    for(ll i = l; i<r; i++)
    {
        ans = min(ans,( ((prefix[i+1]-prefix[l])%100)*((prefix[r+1]-prefix[i+1])%100) + rec(l,i) + rec(i+1,r) )  ) ;
        // cout << l << " " << r  << " " << ans << " " << (prefix[i+1]-prefix[l])*(prefix[r+1]-prefix[i+1]) << '\n';

    }
    // save and return
    return dp[l][r] = ans;
}
// O(n*n*n)

void solve()
{
    cin >> n;
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    prefix[0]=0;
    for(ll i=1; i<=n; i++)
    {
        prefix[i] = prefix[i-1] + arr[i-1];
    }
    memset(dp,-1,sizeof(dp));
    cout << rec(0,n-1) << endl;
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