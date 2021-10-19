#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll const mod = 1e9+7;

void solve()
{
    ll n; cin >> n;
    ll arr[n];
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    vector<ll> sums;
    for(int i=0; i<31; i++)
    {
        ll counts = 0;
        for(ll j=0; j<n; j++)
        {
            if(arr[j]&(1LL<<i)) counts++;
        }
        sums.push_back(counts);
    }
    ll x1 = 0, x2 = 0, x3 = 0, x4 =0;
    for(int i=0; i<31; i++)
    {
        ll cnt = sums[i];
        x1 += (((cnt*(n-cnt))%mod)*((1<<i)%mod))%mod;
        if(x1>=mod)
        {
            x1 -= mod;
        }
        if(cnt > 0)
        {
            x2 += (((1LL<<i)%mod)*((1LL<<(n-1))%mod))%mod;
            if(x2>=mod)
            {
                x2 -= mod;
            }
        }
        x3 += ((((cnt)*(cnt-1)/2)%mod)*((1<<i)%mod))%mod;
        if(x3>=mod)
        {
            x3 -= mod;
        }
        x4 += ((((1<<cnt)-1)%mod)*((1<<i)%mod))%mod;
        if(x4>=mod)
        {
            x4 -= mod;
        }
    }
    cout << x1 << " " << x2 << " " << x3 << " " << x4 << endl;
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