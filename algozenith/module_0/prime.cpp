#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    ll n; 
    cin >> n;
    bool flag = false;
    ll root = sqrt(n);
    for(ll i=2; i<=root; i++)
    {
        if(n%i == 0)
        {
            flag = true;
            break;
        }
    }
    if(flag)
    {
        cout << "NO" << "\n";
    }
    else
    {
        cout << "YES" << "\n";
    }
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