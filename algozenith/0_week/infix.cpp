#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
1 ≤ T ≤ 10^3
1 ≤ |S| ≤ 10^3
'+', '-', '*', '/', '^' (increasing left to right)
*/


void solve()
{
    string str;
    cin >> str;
    stack<char> st;
    map<char,int> order;
    order['^'] = 5;
    order['/'] = 4;
    order['*'] = 3;
    order['-'] = 2;
    order['+'] = 1;
    for(ll i=0; i<str.size(); i++)
    {
        char x = str[i];
        if(x == '^' || x == '/' || x == '*' || x == '-' || x == '+' )
        {
            st.push(order[x]);
            str.erase(i,1);
            i--;
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