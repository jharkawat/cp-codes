#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
add x - if x doesn't present in the set, add element x in the set. Otherwise do nothing.
remove x - remove element x from the set, if it exists. Otherwise do nothing.
find x - find the value at position x (0-indexing) if it exists. Otherwise print -1.
findpos x - find the position (0-indexing) of the element with value x if it exists. Otherwise,
 find the position that the element would have in the set
*/

#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 
typedef tree <int, null_type, less<int>, rb_tree_tag, 
tree_order_statistics_node_update> ordered_set;

void solve()
{
    ll q; cin >> q;
    ordered_set s;
    while(q--)
    {
        string str;
        cin >> str;
        if(str == "add"){
            ll x; cin >> x;
            s.insert(x);
            // cout << "here 1" << endl;
        }
        else if(str == "remove"){
            ll x; cin>>x;
            if(s.find(x) != s.end())
            {
                s.erase(s.find(x));
            }
            // cout << "here 2" << endl;
        }
        else if(str == "find"){
            ll x; cin >> x;
            if(x<s.size())
            {
                cout << *s.find_by_order(x) << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
            // cout << "here 3" << endl;
        }
        else if(str == "findpos"){
            ll x; cin >> x;
            cout << s.order_of_key(x) << "\n";
        }
    }
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