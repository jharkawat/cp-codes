#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
string s,t;
ll dp[3010][3010];
ll gen[3010][3010];
ll m,n;
string solution = "";

ll rec(ll level1, ll level2)
{
    if(level1 == m || level2 == n)
    {
        return 0; 
    }
    if(dp[level1][level2] != -1)
    {
        return dp[level1][level2];
    }
    ll ans;
    if(s[level1]==t[level2])
    {
        ans = 1+rec(level1+1,level2+1);
        gen[level1][level2] = 1;
    }
    else if(rec(level1,level2+1)>=rec(level1+1,level2))
    {
        ans = rec(level1,level2+1);
        gen[level1][level2] = 2;
    }
    else
    {
        ans = rec(level1+1,level2);
        gen[level1][level2] = 3;
    }
    
    return dp[level1][level2] = ans;
}
string sol(ll level1, ll level2)
{    
    if(level1 == m && level2 == n)
    {
        return solution; 
    }

    if(gen[level1][level2]==1)
    {
        // cout << s[level1];
        solution += s[level1];
        return sol(level1+1,level2+1);
    }
    else if(gen[level1][level2]==2)
    {
        return sol(level1,level2+1);
    }
    else if(gen[level1][level2]==3)
    {
        return sol(level1+1,level2);
    }
}

void solve()
{
    cin >> s >> t;
    m = (ll)s.size();
    n = (ll)t.size();
    memset(dp,-1,sizeof(dp));
    rec(0,0);
    cout << sol(0,0) << '\n';
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