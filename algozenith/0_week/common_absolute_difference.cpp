#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n,k; cin >> n >> k;
    map<ll,ll> mpp;
    for(ll i=0; i<n; i++)
    {
        ll p; cin >> p;
        mpp[p]++;
    }
    ll ans = 0;
    for(auto x: mpp)
    {
        if(k!=0)
        {
            if(mpp.find(x.first+k) != mpp.end())
            {
                ans += mpp[x.first+k]*mpp[x.first];
            }
        }
        else
        {
            ans += mpp[x.first]*(mpp[x.first]-1)/2;
        }
    }
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