#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


ll solve()
{
    ll n; cin >> n;
    string str;
    cin >> str; 
    set<ll> st;
    for(ll i=0; i<n; i++)
    {
        if(str[i]=='1')
        {
            st.insert(i+1);
        }
    }
    ll sum = 0; 
    for(ll i=1; i<=n; i++)
    {
        ll ans = 1e18;
        auto it = st.upper_bound(i);
        if(it != st.end())
        {
            ans = min(ans,(*it-i));
        }
        if(it != st.begin())
        {
            it--;
            ans = min(ans,(i-*it));
        }
        sum += ans;
    }
    return sum;
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    // solve();

    ll t; cin >> t;
    ll ans; 
    for(ll i=1; i<=t; i++)
    {
        ans = solve();
        cout << "Case #" << i << ": " << ans << "\n";
    }
}