#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

const ll mod = 1e9 +7;

inline void add(int &a, int b) 
{ a += b; if (a >= mod) a -= mod; } 

inline void sub(int &a, int b) 
{ a -= b; if (a < 0) a += mod; } 

inline int mul(int a, int b) 
{ return (int) ((long long) a * b % mod); }


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
    ll inv = inv_cal((ll)24, mod-2);
    ll num = (n*(n-1))%mod;
    num = (num*(n-2))%mod;
    num = (num*(n-3))%mod;
    // cout << num << " " << inv << endl;
    num = ((num%mod)*(inv%mod))%mod;
    int a = mul(n,n-1);
    int b = mul(a,(mod+1)/2);
    sub(b,n);
    ll ans = (1+b+num)%mod;
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