#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
add x - add element x in the set
erase x - delete element with value x, if it exists
find x - if x is present print “YES”, else print “NO”
print - print the values in set
empty - empty the set
*/


void solve()
{
    ll q; cin >> q;
    set<ll> st;
    while(q--)
    {
        string str;
        cin >> str;
        if(str == "add")
        {
            ll x; cin >> x;
            st.insert(x);
        }
        else if(str == "erase")
        {
            ll x; cin >> x;
            st.erase(x);
        }
        else if(str == "find")
        {
            ll x; cin >> x;
            auto it = st.find(x);
            if(it!=st.end())
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else if(str == "print")
        {
            for(auto x : st)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        else if(str == "empty")
        {
            st.clear();
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