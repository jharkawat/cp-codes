#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
add x - add element x in the set
erase x - delete one element with value x, if it exists
eraseall x - delete all elements with value x, if it exists
find x - if x is present print “YES”, else print “NO”
count x - print the number of times x occurs in the set
print - print the values in set
empty - empty the set
*/


void solve()
{
    ll q; cin >> q;
    multiset<ll> mst;
    while(q--)
    {
        string query;
        cin >> query;
        if(query == "add")
        {
            ll x; cin>> x;
            mst.insert(x);
        }
        else if(query == "erase")
        {
            ll x; cin>> x;
            if(mst.count(x))
            {
                mst.erase(mst.find(x));            
            }
        }
        else if(query == "eraseall")
        {
            ll x; cin>> x;
            if(mst.count(x))
            {
                mst.erase(x);            
            }        }
        else if(query == "find")
        {
            ll x; cin>> x;
            if(mst.count(x))
            {
                cout << "YES" << "\n";
            }
            else
            {
                cout << "NO" << "\n";
            }
        }
        else if(query == "count")
        {
            ll x; cin>> x;
            cout << mst.count(x) << "\n";
        }
        else if(query == "print")
        {
            for(auto x:mst)
            {
                cout << x << " ";
            }
            cout << "\n";
        }
        else if(query == "empty")
        {
            mst.clear();
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