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
    stack<int> st1, st2;
    ll first;
    while(n--)
    {
        string query;
        cin >> query;
        if(query == "push")
        {
            ll x; cin >> x;
            if(st1.empty())
            {
                // cout << "yes " << x << "\n"; 
                first = x;
            }

            st1.push(x);
        }
        else if(query == "pop")
        {
            if(!st1.empty() && st2.empty())
            {
                ll siz = (int)st1.size();
                for(ll i=0; i<siz-1; i++)
                {
                    st2.push(st1.top());
                    st1.pop();
                }
                cout << st1.top() << endl;
                st1.pop();
            }
            else if(!st2.empty())
            {
                cout << st2.top() <<"\n";
                st2.pop();
            }
        }
        else if(query == "front")
        {
            if(st2.empty())
            cout << first << endl;
            else
            {
                cout << st2.top() << "\n";
            }
        }
        else 
        {
            cout << 0 << endl;
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