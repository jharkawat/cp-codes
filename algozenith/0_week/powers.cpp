#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll ans =0;
    ll n; cin >> n;
    map<ll,ll> nos;
    ll arr[n];
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
        nos[arr[i]]++;
    }
    ll x = 1;
    for(int i=1; i<32; i++)
    {
        for(int i=0; i<n; i++)
        {
            nos[arr[i]]--;
            if(nos.count(x-arr[i]))
            {
                ans += nos[x-arr[i]];
            }
        }
        for(ll i=0; i<n; i++)
        {
            nos[arr[i]]++;
        }
        x*=2;
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
    
    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}