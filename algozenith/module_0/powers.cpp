#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

ll number_to_find(ll x)
{
    ll ans = 1;
    while(ans<x)
    {
        ans *= 2;
    }
    return (ans-x);
}

void solve()
{
    ll n; cin >> n;
    vector<ll> arr(n);
    map<ll,ll> mpp;
    ll ans =0;
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i]
        mpp[arr[i]].push_back(i);
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