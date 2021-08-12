#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n; cin >> n;
    map<ll,ll> mpp;
    ll ans = 0;
    ll count = 0;
    while(n--)
    {
        ll start, end;
        cin >> start >> end;
        mpp[start]++;
        if(mpp.count(end))
        {
            mpp[end]--;
        } 
        else
        {
            mpp[end] = -1;
        }
    }
    // for(auto x: mpp)
    // {
    //     cout << x.first << " " << x.second << endl;
    // }
    for(auto x : mpp)
    {
        count += x.second;
        // cout << count << endl;
        ans = max(ans,count);
    }
    cout << ans << endl;
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}