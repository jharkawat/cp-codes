#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,k;
ll arr[100100];
ll dp[100100];

bool rec(ll x)
{
    if(x==0)
    {
        return 0;
    }
    if(dp[x]!=-1)
    {
        return dp[x];
    }
    ll ans =1;
    for(ll i=0; i<n; i++)
    {
        if(x>=arr[i])
        {
            ans &= rec(x-arr[i]);
        }
    }
    if(ans)
    return dp[x] = 0;
    else
    return dp[x] = 1;
}

void solve()
{
    cin >> n>> k;
    memset(dp,-1,sizeof(dp));
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    bool ans = rec(k);
    if(ans)
    cout << "First\n";
    else 
    cout << "Second\n";
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