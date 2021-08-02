#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    ll n; 
    cin >> n;
    ll odd;
    cin >> odd;
    n--;
    while(n--)
    {
        ll p;
        cin >> p;
        odd ^= p;
    }
    cout << odd << "\n";
}

signed main()
{
    IOS
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}