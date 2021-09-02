#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

ll arr[1000100];
ll dp[1000100][2];
ll n;

ll rec(ll level, ll last)
{
    // pruing

    // base case
    if(level>(n-3))
    {
        return arr[level];
    }

    // cache
    {
        if(dp[level][last] != -1)
        {
            return dp[level][last];
        }
    }

    // logic
    ll ans = 0;
    if(last == 0)
    {
        ans = max(rec(level+1,1), arr[level]+rec(level+2,0));
    }
    else 
    {
        ans = arr[level]+rec(level+2,0);
    }

    // save and return 
    return dp[level][last] = ans; 
}

void solve()
{
    cin>> n;
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }    
    memset(dp,-1,sizeof(dp));
    ll final = max(rec(1,1), arr[0]+rec(2,0));
    cout << final << '\n';
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