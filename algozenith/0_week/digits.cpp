#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    string n;
    getline(cin,n);
    ll sum = 0;
    for(ll i=0; i<n.size(); i++)
    {
        sum += n[i]-'0';
    }
    cout << sum << '\n';
}

// O(n)

signed main()
{
    IOS
    ll t;
    cin >> t;
    string temp;
    getline(cin,temp);
    while(t--){
        solve();
    }
}