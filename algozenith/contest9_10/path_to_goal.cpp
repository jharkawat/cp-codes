#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,x,y,m;
ll dp[1010][2550];
string str;
ll const mod = 1e9+7;

ll rec(ll level, ll pos)
{
    if(level == m)
    {
        if(pos == y)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if(dp[level][pos] != -1)
    {
        return dp[level][pos];
    }

    ll ans = rec(level+1,pos);
    if(pos>0 && str[level] == 'l')
    {
        ans += rec(level+1,pos-1);
    }
    if(pos<n && str[level] == 'r')
    {
        ans += rec(level+1,pos+1);
    }

    ans = ans%mod;

    return dp[level][pos] = ans;

}

void solve()
{
    cin >> str;
    m = str.size();
    cin >> n >> x >> y;
    memset(dp,-1,sizeof(dp));
    cout << rec(0,x) << endl;
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