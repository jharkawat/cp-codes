#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    // int q, x;
    // cin >> q >> x;
    // vector<int> v[x];
    // set<int> s;
    // for (int i = 0; i <= q; ++i) {
    //     s.insert(i);
    // }
    // while (q--) {
    //     int t;
    //     cin >> t;
    //     t%=x;
    //     if (v[t].empty()) {
    //         v[t].push_back(t);
    //     }
    //     else {
    //         int xx=v[t].back();
    //         v[t].push_back(xx+x);
    //         t=xx+x;
    //     }
    //     s.erase(t);
    
    //     cout << *s.begin() << " ";
    // }
    // cout << "\n";


    ll q,x;
    cin >> q >> x;
    set<ll> st;
    for(ll i=0; i<=q; i++)
    {
        st.insert(i);
    }
    vector<ll> vec[x];
    while(q--)
    {
        ll y;
        cin >> y;
        y%=x;
        if(vec[y].empty())
        {
            vec[y].push_back(y);
        }
        else
        {
            ll p = vec[y].back();
            vec[y].push_back(p+x);
            y = p+x;
        }
        st.erase(y);
        // cout << "set \n";
        // for(auto m: st)
        // {
        //     cout << m << " ";
        // }
        // cout << "\n";
        cout << *st.begin() << " ";
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