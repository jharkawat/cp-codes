#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

ll n;
ll arr[100100];
string s;
ll dp[100100][4];

ll rec(ll level, ll type)
{
    if(level == n)
    {
        return 0;
    }
    if(dp[level][type] != -1)
    {
        return dp[level][type];
    }
    ll ans = INT_MAX; 
    if(type == 0)
    {
        if(s[level] == 'h')
        {
            ans = min(ans,min(rec(level+1,1),arr[level]+rec(level+1,0)));
        }
        else
        {
            ans = min(ans,rec(level+1,0));
        }
    }
    else if(type == 1)
    {
        if(s[level] == 'a')
        {
            ans = min(ans,min(rec(level+1,2),arr[level]+rec(level+1,1)));
        }
        else
        {
            ans = min(ans,rec(level+1,1));
        }
    }
    else if(type == 2)
    {
        if(s[level] == 'r')
        {
            ans = min(ans,min(rec(level+1,3),arr[level]+rec(level+1,2)));
        }
        else
        {
            ans = min(ans,rec(level+1,2));
        }
    }
    else if(type == 3)
    {
        if(s[level] == 'd')
        {
            ans = min(ans,arr[level]+rec(level+1,3));
        }
        else
        {
            ans = min(ans,rec(level+1,3));
        }
    }
    // cout << level << " " << type << " " << ans << endl; 
    return dp[level][type] = ans;
}


void solve()
{
    cin >> n;
    cin >> s;
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << rec(0,0) << endl;
    // for(ll i=0; i<n; i++)
    // {
    //     for(ll j=0; j<4; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
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
        // cout << "here \n";
        solve();
    }
}