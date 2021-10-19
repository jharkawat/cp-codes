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
    ll arr[n];
    for(ll i=0;i<n; i++)
    {
        cin>> arr[i];
    }    
    vector<ll> bits;
    for(ll i=0; i< 31; i++)
    {
        ll counts = 0;
        for(ll j=0; j<n; j++)
        {
            if(arr[j]&(1<<i)) counts++;
        }
        bits.push_back(counts);
    }
    ll ans = 0; 
    for(ll i=0; i<n; i++)
    {
        ll numbers = 0;
        for(ll i=0;i<31; i++)
        {
            if(bits[i]>0)
            {
                numbers|=(1<<i);
                bits[i]--;
            }
        }
        ans += numbers*numbers;
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