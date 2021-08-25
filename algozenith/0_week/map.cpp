#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
add x y - add student name X (string in lowercase alphabets) with marks y (integer). If it already exists, update.
erase x - erase marks of student with name x, if the entry exists
print x - print marks of student with name x, if entry is not there for x, print 0.
*/


void solve()
{
    ll q; cin >> q;
    map<string,int> mpp;
    while(q--)
    {
        string query;
        cin >> query;
        if(query == "add")
        {
            string name; 
            ll mark;
            cin >> name >> mark;
            mpp[name] = mark;
        }
        else if(query == "erase")
        {
            string name;
            cin >> name;
            mpp.erase(name);
        }
        else if(query == "print")
        {
            string name;
            cin >> name;
            if(mpp.find(name) == mpp.end())
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << mpp[name] << "\n";
            }
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