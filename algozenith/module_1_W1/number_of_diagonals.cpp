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


void solve()
{
    int n; cin >> n;
    int a = mul(n,n-1);
    int b = mul(a,(mod+1)/2);
    sub(b,n);
    cout << b << "\n";
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