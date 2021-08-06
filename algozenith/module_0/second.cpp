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
    set<ll> st;
    while(n--)
    {
        ll p; cin >> p;
        st.insert(p);
    }
    if(st.size()>1)
    {
        auto it = st.begin();
        it++;
        cout << *it << "\n";
    }
    else
    {
        cout << -1 << endl;
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