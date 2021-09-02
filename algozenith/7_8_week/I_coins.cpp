#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

double dp[3000][6000];
bool done[3000][6000];
double prob[3000];
ll n;

double rec(ll level, ll depth)
{
    if(n == level)
    {
        if(depth > 0)
        return 1;
        else 
        return 0;
    }
    if(done[level][n+depth] != false)
    {
        return dp[level][n+depth];
    }
    double ans = prob[level]*rec(level+1,depth+1) + (1-prob[level])*rec(level+1,depth-1);
    // cout << ans << endl;
    // cout << level << " " << depth << endl; 
    done[level][n+depth]=true;
    return dp[level][n+depth] = ans;
}

// O(2(n^2)*2) ~ 10^7

void solve()
{
    cin >> n;
    // memset(dp,-1,sizeof(dp));
    for(ll i=0; i<n; i++)
    {
        cin >> prob[i];
    }
    cout << fixed << setprecision(15) << rec(0,0) << "\n";
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