#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n; cin >> n;
    ll temp;
    cin >> temp;
    for(int i=1; i<n; i++)
    {
        ll nos;
        cin >> nos;
        temp = __gcd(temp,nos);
    }
    if(temp ==1)
    {
        cout << "No\n";
    }
    else cout << "Yes\n";

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