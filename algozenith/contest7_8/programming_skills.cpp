#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,k;
ll arr[10010];
ll dp[10010];

ll rec(ll level)
{
    // pruning

    // basecase
    if(level == n)
    {
        return 0; 
    }

    // cache
    if(dp[level] != -1)
    {
        return dp[level];
    }

    // logic
    ll ans = 0;
    ll maxi = 0;
    for(ll i=0; i<k; i++)
    {
        if((level + i) < n)
        {
            maxi = max(maxi,arr[level+i]);
            ans = max(ans, (maxi*(i+1)+rec(level+i+1)) );
        }
    }

    // save and return

    return dp[level] = ans;
}


void solve()
{
    cin >> n >> k;
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
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

    // ll t; cin >> t; 
    // while(t--)
    // {
    //     solve();
    // }
}