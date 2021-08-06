#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
add x y - add student name X (string) for marks y (integer). If it already exists, add a new entry.
erase x - erase the first current entry of student with name x
eraseall x - erase all entries of student with name x
print x - print the first entry of marks of student with name x, if entry is not there for x, print 0.
*/


void solve()
{
    ll q; cin >> q;
    multimap<string, ll> mmpp;
    while(q--)   // O(n)
    {
        string str;
        cin >> str;
        if(str == "add"){
            string name;
            ll marks;
            cin >> name >> marks;
            mmpp.insert({name,marks});       // O(logn)
        }
        else if(str == "erase"){ 
            string name;
            cin >> name;
            if(mmpp.count(name))              // O(logn)   
            {
                mmpp.erase(mmpp.find(name));   // O(logn)
            }
        }
        else if(str == "eraseall"){
            string name;
            cin >> name;
            while(mmpp.count(name))            // O(logn*|s|)
            {
                mmpp.erase(mmpp.find(name));
            }
        }
        else if(str == "print"){
            string name;
            cin >> name;
            auto it = mmpp.find(name);
            if(it != mmpp.end())
            {
                cout << it->second << "\n";
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }
}

// O(|s|*n*logn)

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