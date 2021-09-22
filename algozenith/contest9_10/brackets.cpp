#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n;
ll dp[202][110][110];
ll const mod = 1e9+7;

ll rec(ll level, ll open1, ll open2)
{
    // base case
    if(level == n)
    {
        // cout << level << " " << open1 << " " << open2  << '\n';
        if(open1 == 0 && open2 == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // cache
    if(dp[level][open1][open2] != -1)
    {
        return dp[level][open1][open2];
    }

    // logic
    ll ans = 0; 
    if(open1!=0)
    {
        ans += rec(level+1, open1+1, open2);
        ans += rec(level+1, open1-1, open2);
    }
    else
    {
        ans += rec(level+1, open1+1, open2);
        ans += rec(level+1, open1, open2+1);
        if(open2>0)
        {
            ans += rec(level+1, open1, open2-1);
        } 
    }

    ans = ans%mod;

    // cout << level << " " << open1 << " " << open2 << " " << ans << '\n';
    return dp[level][open1][open2] = ans;
}

void solve()
{
    cin >> n;
    memset(dp,-1,sizeof(dp));
    cout << rec(0,0,0) << endl;
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