#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9 + 7;

void solve()
{
    ll n, ans; 
    cin >> n;
    ans =1;
    while(n--)
    {
        ll p; cin >> p;
        ans *= p;
        ans %= mod;
    }
    cout << ans << endl;

}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}