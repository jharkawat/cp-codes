#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    string change;
    getline(cin, change);
    for(ll i=0; i<change.size(); i++)
    {
        char c = change[i];
        if(islower(c))
        {
            change[i] = toupper(c);
        }
        else if(isupper(c))
        {
            change[i] = tolower(c);
        }  
    }
    cout << change << "\n";
}

signed main()
{
    IOS
    ll t; cin >> t;
    string temp;
    getline(cin , temp);
    while(t--)
    {
        solve();
    }
}