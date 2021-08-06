#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n,m;
    cin >> n >> m;
    set<ll> st;
    for(ll i=0; i<n; i++)
    {
        ll p; cin >> p;
        st.insert(p);
    }
    for(ll i=0; i<m; i++)
    {
        ll p; cin >> p;
        if(st.count(p))
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
            st.insert(p);
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