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
    map<string,int> mpp;
    while(n--)
    {
        string name;
        cin >> name;
        if(mpp.count(name))
        {
            cout << name << mpp[name] << "\n";
            mpp[name]++;
        }
        else
        {
            mpp[name] = 1;
            cout << "OK" << "\n";
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