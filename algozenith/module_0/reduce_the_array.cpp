#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n; cin>> n;
    multiset<ll> st;
    for(ll i=0; i<n; i++)
    {
        ll p; cin>> p;
        st.insert(p);
    }
    ll ans = 0;
    while(st.size()!=1)
    {
        auto it = st.begin();
        auto it2 = it++;
        ans += (*it + *it2);
        st.insert(*it + *it2);
        st.erase(it);
        st.erase(it2);
    }
    cout << ans << "\n";
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