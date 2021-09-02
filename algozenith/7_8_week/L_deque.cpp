#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll arr[3000];
ll dp[3010][3010];
ll n; 

ll rec(ll l, ll r)
{
    if(l==r)
    {
        return arr[l];
    }
    if(dp[l][r] != -1)
    {
        return dp[l][r];
    }
    ll ans = max(arr[l]-rec(l+1,r),arr[r]-rec(l,r-1));
    return dp[l][r] = ans;

}

void solve()
{
    cin >> n;
    memset(dp,-1,sizeof(dp));
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << rec(0,n-1) << "\n";
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