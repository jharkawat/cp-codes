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
    ll maxi = 0;
    ll ans = 0;
    for(ll i=0; i<n; i++)
    {
        ll p;
        cin >> p;
        if(maxi<=p)
        {
            maxi = p;
            ans++;
        }
        mpp[p]++;
    }
// O(nlogn)

    for(auto x:mpp)
    {
        ans = max(ans,x.second);
    }
// O(|mpp|)    

    cout << ans << "\n";
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