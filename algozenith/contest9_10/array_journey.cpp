#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

struct monotone_deque
{
    deque<ll> dq;

    void insert(ll x)
    {
        while(!dq.empty() && dq.back()<x)
        {
            dq.pop_back();
        }
        dq.push_back(x);
    }

    void remove(ll x)
    {
        if(dq.front() == x)
        {
            dq.pop_front();
        }
    }

    ll getmax()
    {
        return dq.front();
    }

};



void solve()
{
    monotone_deque dq;
    ll n,k;
    cin >> n;
    ll arr[n];
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    ll dp[n+1];
    dp[0] = 0; 
    for(ll i=1; i<n; i++)
    {
        dq.insert(arr[i-1]+dp[i-1]);
        if(i-k-1>=0)
        {
            dq.remove(arr[i-k-1]+dp[i-k-1]);
        }
        dp[i] = dq.getmax();
        // cout << dp[i] << " ";
    }
    // cout << endl;
    cout << dp[n-1] + arr[n-1] << endl;
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