#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    vector<ll> v;
    ll n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        if(s=="add")
        {
            ll p; cin>>p;
            v.push_back(p);
        }
        else if(s=="remove")
        {
            if(!v.empty()) 
            {
                v.pop_back();
            }    
        }
        else if(s=="print")
        {
            ll x; 
            cin >> x;
            if(x< (int)v.size())
            {
                cout << v[x] << "\n"; 
            }
            else
            {
                cout << "0" << "\n" ;
            }
        }
        else
        {
            v.clear();
        }
    }

}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}