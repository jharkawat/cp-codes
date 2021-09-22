#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
vector<ll> fibo;

void solve()
{
    ll n; cin >> n;
    auto it = upper_bound(fibo.begin(), fibo.end(), n);
    ll ans = 0;
    while(n!=0)
    {
        // cout << ans << " " << n << " " << *it << endl;
        ans++;
        it--;
        n -= *it;
        it = upper_bound(fibo.begin(), fibo.end(), n);
    }
    cout << ans << '\n';
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    // solve();

    ll x=0;
    fibo.push_back(1);
    fibo.push_back(1);
    ll i=1;
    while(x<1e9)
    {
        x = fibo[i]+fibo[i-1];
        i++;
        fibo.push_back(x);
        // cout << x << endl;
    }

    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}