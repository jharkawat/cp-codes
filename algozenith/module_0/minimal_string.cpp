#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    string str;
    cin >> str;
    multiset<char> st;
    for(ll i=0; i<str.size(); i++)
    {
        st.insert(str[i]);
    }
    stack<char> T;
    string U;
    U.clear();
    for(ll i=0; i<str.size(); i++)
    {
        // cout << str[i] << " " << *st.begin() << "\n";
        if(str[i] == *st.begin())
        {
            while(!T.empty() && T.top()<=str[i])
            {   
                U += T.top();
                T.pop();
            }
            U += str[i];
            st.erase(st.find(str[i]));
        }cd
        else
        {
            while(!T.empty() && T.top()<=*st.begin())
            {   
                U += T.top();
                T.pop();
            }
            T.push(str[i]);
            st.erase(st.find(str[i]));
        }
    }
    while(!T.empty())
    {
        U += T.top();
        T.pop();
    }
    cout << U << "\n";

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