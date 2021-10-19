#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,k;
map<ll,ll> mpp;

bool check(ll x)
{
    ll sums = 0;
    for(auto v : mpp)
    {
        sums += min(k,v.second);
    }
    return sums >= k*x;
}

void solve()
{
    cin >> n >> k;
    mpp.clear();
    for(ll i=0; i<n; i++)
    {
        ll p; cin >> p;
        mpp[p]++;
    }
    ll lo = 0, hi = n/k;
    ll ans  = -1;
    while(lo<=hi)
    {
        ll mid = (lo+hi)/2;
        if(check(mid))
        {
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
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