#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll query; cin >> query;
    set<ll> st1, st2;
    while (query--)
    {
        ll t,x;
        cin >> t >>x;
        if(t==1)
        {
            st1.insert(x);
            if(!st2.empty() || st2.find(x) != st2.end())
            {
                st2.erase(x);
                st2.insert(x+1);
            }
            else
            {
                st2.insert(x+1);
            }
        }
        else if(t==2)
        {
            if(st1.find(x) == st1.end())
            {
                cout << x << "\n";
            }
            else 
            {
                auto it = st2.upper_bound(x);
                cout << *it << "\n";
            }
        }
    }
}


/*
LOGIC 1: logic sahi hai lekin tle a rha ha
void solve()
{
    ll query; cin >> query;
    set<ll> st;
    while(query--)
    {
        ll t,x;
        cin >> t >> x;
        if(t==1)
        {
            st.insert(x);
        }
        else if(t==2)
        {
            auto it = st.find(x);
            if(it == st.end())
            {
                cout << x << "\n";
            }
            else
            {
                it = st.upper_bound(x);
                if(x+1<*it)
                {
                    cout << x+1 << "\n";
                }
                else
                {
                    x++;
                    while(1)
                    {
                        if(*it>x || it == st.end())
                        {
                            cout << x << '\n';
                            break;
                        }
                        else
                        {
                            it++; x++;
                        }
                    }
                }
            }
        }
    }    
}
*/


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