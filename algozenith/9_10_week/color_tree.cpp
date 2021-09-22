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
    vector<ll> vec(n+1,0);
    // for(auto x : vec)
    // {
    //     cout << x << endl;
    //     // ans = max(ans,x);
    // }

    for(ll i=0; i<n-1; i++)
    {
        ll a,b;
        cin >>a >> b;
        // cout << a << " " << b << endl;
        vec[a]++;
        vec[b]++;
    }
    ll ans = 0; 
    for(auto x : vec)
    {
        // cout << x << endl;
        ans = max(ans,x);
    }
    cout << ans+1 << endl;
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    solve();

    // ll t; cin >> t; 
    // while(t--)
    // {
    //     solve();
    // }
}