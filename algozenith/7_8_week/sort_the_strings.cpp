#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n;
ll arr[100100];
string lists[100100];
ll dp[100100][2];

ll rec(ll level, ll pos)
{
    // prrning

    // base case
    if(level == n)
    {
        return 0;
    }

    // cache
    if(dp[level][pos] != -1)
    {
        return dp[level][pos];
    }

    // logic
    ll ans = -1;
}


void solve()
{
    cin >> n;
    for(ll i=0;i<n; i++)
    {
        cin >> arr[i];
    }    
    for(ll i=0;i<n; i++)
    {
        cin >> lists[i];
    }    
    memset(dp,-1,sizeof(dp));
    cout << min(rec(0,0),arr[0]+rec(0,1)) << '\n';
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