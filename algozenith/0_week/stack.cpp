#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
    1 ≤ T ≤ 10^6
    1 ≤ Q ≤ 10^6
    1 ≤ X ≤ 10^6
    It is guaranteed that the sum of Q over all test cases does not exceed 106
*/


void solve()
{
    ll q;
    cin >> q;
    stack<ll> st;
    while(q--)
    {
        string str;
        cin >> str;
        if(str == "add")
        {
            ll x; cin >> x;
            st.push(x);
        }
        else if(str == "remove")
        {
            if(!st.empty())
            {
                st.pop();
            }
        }
        else if(str == "print")
        {
            if(!st.empty())
            {
                cout << st.top() << "\n";
            }
            else 
            {
                cout << "0" << endl;
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