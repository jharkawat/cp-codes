#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

ll n,h,s,t;
ll arr[101];
ll dp[101][101];

ll rec(ll level, ll dev)
{
    // pruning

    // base case
    if(level == n)
    {
        return dev*t;   
    }

    // cache
    if(dp[level][dev] != -1)
    {
        return dp[level][dev];
    }

    // logic
    ll ans = 1e18; 
    if(dev<=arr[level])
    {
        ans = (arr[level]-dev)*h + arr[level]*s + rec(level+1,arr[level]);
    }
    else 
    {
        ll i=0;
        while(dev-i>=arr[level])
        { 
            ans = min(ans, i*t + (dev-i)*s + rec(level+1,dev-i));
            i++;
        }
    }

    // cout << level << " " << dev << " " << ans << endl;
    // save and return 
    return dp[level][dev] = ans;

}

void solve()
{
    cin >> n >> h >> s >> t;
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << rec(0,0) << '\n';
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