#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,k;
vector<ll> seats;

void solve()
{
    cin >> n >> k;
    seats.resize(n);
    ll lo = 1e18, hi;
    for(ll i=0; i<n; i++)
    {
        cin >> seats[i];
    }
    sort(seats.begin(), seats.end());
    for(ll i=1; i<n; i++)
    {
        lo = min(lo,seats[i]-seats[i-1]);
    }
    hi = seats[n-1]-seats[0];
    ll ans = -1;
    while(lo<=hi)
    {
        mid 
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