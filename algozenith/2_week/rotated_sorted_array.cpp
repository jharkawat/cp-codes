#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll arr[100100];


bool check(ll x)
{
    return arr[0] > arr[x];
}

void solve()
{
    ll n; cin>> n;
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }    
    ll lo = 0, hi = n-1, mid;
    ll ans = 0;
    while(lo<=hi)
    {
        mid = (hi+lo)/2;
        if(check(mid) == 1)
        {
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
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