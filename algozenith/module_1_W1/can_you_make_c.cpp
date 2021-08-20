#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll a,b,c;
    cin >> a >> b >> c;
    ll temp = __gcd(a,b);
    ll x = (ll)c/temp;
    if(x*temp == c)
    {
        cout << "YES \n";
    }
    else 
    {
        cout << "NO \n";
    }
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