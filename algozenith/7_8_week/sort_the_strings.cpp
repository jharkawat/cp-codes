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
string rev[100100];
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
    ll ans = 1e15;
    {
        if(pos == 0)
        {
            if(lists[level]>lists[level-1])
            {
                ans = min(ans,rec(level+1,0));
            }
            if(rev[level]>lists[level-1])
            {
                ans = min(ans,rec(level+1,1)+arr[level]);
            }
        }
        else if(pos == 1)
        {
            if(lists[level]>rev[level-1])
            {
                ans = min(ans,rec(level+1,0));
            }
            if(rev[level]>rev[level-1])
            {
                ans = min(ans,rec(level+1,1)+arr[level]);
            }
        }
    }

    // save and return 
    return dp[level][pos] = ans;
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
        string temp;
        cin >> temp;
        lists[i] = temp;
        reverse(temp.begin(),temp.end());
        rev[i]= temp;
    }    
    memset(dp,-1,sizeof(dp));
    if(min(rec(1,0),arr[0]+rec(1,1))>=1e15)
    {
        cout << "-1" << '\n';
    }
    else
    {
        cout << min(rec(1,0),arr[0]+rec(1,1)) << '\n';
    }
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