#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    ll a,b;
    cin >> a >> b;
    a = a^b;
    b = a^b;
    a = a^b;
    cout << a << " " << b << '\n';
}

// O(1)

signed main()
{
    IOS
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}