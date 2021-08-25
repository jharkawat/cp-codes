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
    stack<ll> st;
    ll arr[n];
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
        while(!st.empty() && arr[st.top()-1]>=arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            cout << "0";
        }
        else
        {
            cout << st.top();
        }
        st.push(i+1);
    }
    cout << "\n";
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