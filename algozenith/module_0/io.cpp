#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    ll n;
    string m;
    cin >> n >> m;
    ll pos;
    for(ll i=0; i<m.size(); i++)
    {
        if(m[i] == '.')
        {
            pos = i; 
            break;
        }
    }
    ll x,y;
    if(pos == 0)
    {
        x = 0;
        string temp = m.substr(1,(m.size()-1));
        y = stoll(temp);
    }
    else
    {
        string temp = m.substr(0,pos);
        x = stoll(temp);
        temp = m.substr(pos+1,m.size()-pos-1);
        y = stoll(temp);
    }
    cout << (y+n) << "." << (x+n) << '\n';
} 

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