#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    ll n;
    cin >> n;
    ll zero;
    zero = n/5;
    ll count = -1;
    ll nos = n;
    while(nos)
    {
        nos /= 10;
        zero++;
    }
    zero--;
    while(n)
    {
        n /= 5;
        count++;
    }
    zero += count*(count-1)/2;
    cout << zero << endl;
}

signed main()
{
    IOS
    ll t; cin >> t;
    while(t--)
    {
        solve();
    }
}