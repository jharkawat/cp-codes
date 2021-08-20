#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

const ll mod = 1e9 +7;

ll inv_cal(ll a , ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b%2 == 1)
        {
            ans = ((ans%mod)*(a%mod))%mod;
        }
        a = ((a%mod)*(a%mod))%mod;
        b = b/2;
    }
    return ans%mod;
}

void solve()
{
    ll n; cin >> n;
    if(n ==3)
    {
        cout << 0 << endl;
        return;
    }
    ll inv = inv_cal((ll)24, mod-2);
    ll num = (n*(n-1))%mod;
    num = (num*(n-2))%mod;
    num = (num*(n-3))%mod;
    // cout << num << " " << inv << endl;
    num = ((num%mod)*(inv%mod))%mod;
    cout << num <<"\n";
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