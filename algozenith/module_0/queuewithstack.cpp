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
            if(!st1.empty())
            {
                ll siz = (int)st1.size();
                for(ll i=0; i<siz-1; i++)
                {
                    st2.push(st1.top());
                    st1.pop();
                }
                cout << st1.top() << endl;
                st1.pop();
                if(!st2.empty())
                {
                    ll siz2 = (int)st2.size();
                    for(ll i=0; i<siz2; i++)
                    {
                        if(i==0)
                        {
                            first = st2.top();
                        }
                        st1.push(st2.top());
                        st2.pop();
                    }
                }
            }
        }
        else if(query == "front")
        {
            cout << first << endl;
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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}