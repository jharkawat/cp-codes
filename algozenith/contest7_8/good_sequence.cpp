#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,k;
ll dp[2010][2010];

ll rec(ll level, ll num)
{
    // base case
    if(level == 0)
    {
        return 0;
    }

    // cache
    if(dp[level][num] != -1)
    {
        return dp[level][num];
    }

    // logic

}



void solve()
{
    
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    // solve();

    memset(dp,-1,sizeof(dp));
    rec(2000,2000);

    ll t; cin >> t; 
    while(t--)
    {
        cin >> n >> k;
        cout << rec(n,k) << '\n';
    }
}