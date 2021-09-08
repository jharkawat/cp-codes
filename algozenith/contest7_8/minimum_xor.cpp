#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

ll n;
ll arr[200100];
ll dp[200100];
ll pre[200100];

ll rec(ll level)
{
    // pruning

    // base case
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
    ll ans = 1e18;
    ll temp = 1;
    for(ll i=0; i<22; i++)
    {
        ll sum  = pre[level+temp]^pre[level];
        if((level + temp) <= n)
        {
            ans = min(ans, (sum+rec(level+temp)));
            // cout << level << " " << temp << " " << sum << " " << ans << '\n';
        }
        else
        {
            break;
        }
        temp = temp*2;

    }
    // return and save

    return dp[level] = ans;
}

void solve()
{
    cin >> n;
    pre[0]=0;
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
        pre[i+1] = pre[i]^arr[i];
        // cout << pre[i+1] << " ";
    }
    // cout << endl;
    memset(dp,-1,sizeof(dp));
    cout << rec(0) << '\n';
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