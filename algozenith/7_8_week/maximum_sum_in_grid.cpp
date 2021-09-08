#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,m;
vector<vector<ll>> dp, arr;
vector<vector<bool>> dones;

ll rec(ll row, ll col)
{
    // base case
    if(row<0 || col<0)
    {
        return 0;
    }

    // cache 
    if(dones[row][col] == true)
    {
        return dp[row][col];
    }

    // logic
    ll ans = max(arr[row][col], arr[row][col]+rec(row-1,col)+rec(row,col-1)-rec(row-1,col-1));

    // save and return
    dones[row][col] = true;
    return dp[row][col] = ans;
}

void solve()
{
    cin >> n >> m;
    dp.clear();
    arr.clear();
    dones.clear();
    dp.resize(n, vector<ll>(m));
    arr.resize(n, vector<ll>(m));
    dones.resize(n, vector<bool>(m));
    for(ll i =0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            cin >> arr[i][j];
            dones[i][j] = false;
        }
    }
    ll ans = rec(0,0);
    for(ll i =0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            ans = max(ans,rec(i,j));
        }
    }
    cout << ans << endl;

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