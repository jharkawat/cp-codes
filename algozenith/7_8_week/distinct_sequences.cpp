#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
string str;
ll dp[100100];
ll arr[26];
ll const mod = 1e9 +7;

ll rec(ll level)
{
    // base case
    if(level == 0)
    {
        return 1;
    }

    // cache
    if(dp[level] != -1)
    {
        return dp[level];
    }

    // logic
    ll ans = 0; 
    for(ll i=arr[str[level-1]-'A']; i<level; i++)
    {
        ans += rec(i);
    }
    arr[str[level-1]-'A'] = level;

    // save and return

    return dp[level] = ans%mod;

}

void solve()
{
    cin >> str;
    memset(dp,-1,sizeof(dp));
    memset(arr,0,sizeof(arr));
    // cout << rec(str.size()) << '\n';
    ll ans = 0;
    for(ll i=0; i<=str.size(); i++)
    {
        ans += rec(i); 
        // cout << rec(i) << endl;
    }
    cout << ans%mod <<endl;
    // for(ll i=0; i<26; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
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