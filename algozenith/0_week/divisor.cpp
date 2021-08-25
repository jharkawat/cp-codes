#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    ll n; 
    cin >> n;
    ll count = 0;
    for(ll i=1; i*i<=n; i++)
    {
        if(n%i == 0)
        {
            count += 2;
        }
    }
    if(sqrt(n)*sqrt(n) == n)
    {
        count--;
    }
    cout << count << endl;
}

// O(root(n))

signed main()
{
    IOS
    ll t; cin >> t;
    while(t--)
    {
        solve();
    }
}