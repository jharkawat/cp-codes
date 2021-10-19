#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,k;
ll arr[100100];

bool check(ll x)
{
    ll painters = 0; 
    ll left = 0;
    for(ll i=0; i<n; i++)
    {
        if(left>=arr[i])
        {
            left -= arr[i];
        }
        else
        {
            left = x-arr[i];
            painters++;
        }
    }
    return painters<=k;
}

void solve()
{
    cin >> n >> k;
    ll lo = -1, hi = 0;
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
        lo = max(lo,arr[i]);
        hi += arr[i];
    }
    ll ans = -1;
    while(lo<=hi)
    {
        ll mid = (lo+hi)/2;
        if(check(mid))
        {
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    cout << ans << '\n';
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