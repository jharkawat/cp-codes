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
    vector<ll> vec1(n),vec2(n);
    for(ll i=0; i<n; i++)
    {
        cin >> vec1[i];
    }
    for(ll i=0; i<n; i++)
    {
        cin >> vec2[i];
    }
    multiset<ll> st;
    
    for(ll i=0; i<n; i++)
    {
        st.insert(vec1[i]-vec2[i]);
    }
    ll ans = 0;
    for(auto x:st)
    {
        if(x<=0)
        {
            ans += distance(st.upper_bound(0-x),st.end());
            st.erase(st.begin());
        }
        else
        {
            break;
        }
    }
    ans += (st.size())*(st.size()-1)/2;
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