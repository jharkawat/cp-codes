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


void solve()
{
    ll q; cin >> q;
    set<ll> s;
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
                s.erase(x);
            }
            // cout << "here 2" << endl;
        }
        else if(str == "find"){
            ll x; cin >> x;
            if(x<s.size())
            {
                auto it = s.begin();
                while(x--)
                {
                    it++;
                }
                cout << *it << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
            // cout << "here 3" << endl;
        }
        else if(str == "findpos"){
            ll x; cin >> x;
            ll pos = 0;
            if(!s.empty())
            {
                auto it = s.find(x);
                if(it != s.end())
                {
                    pos = distance(s.begin(),s.find(x));
                    cout << pos << "\n";
                    // cout << "here 5" << endl;
                }
                else
                {
                    ll pos = distance(s.begin(),s.upper_bound(x));
                    cout << pos << "\n";
                }
            }
            // cout << "here 4" << endl;
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