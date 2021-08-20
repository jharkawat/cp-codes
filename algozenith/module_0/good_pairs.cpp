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
    vector<ll> st;
    
    for(ll i=0; i<n; i++)
    {
        st.push_back(vec1[i]-vec2[i]);
    }
    sort(st.begin(), st.end());
    ll ans = 0;
    int i=0;
    for(i=0; i<n; i++)
    {
        if(st[i]>0)
        {
            break;
        }
        if(st[i]<=0)
        {
            // cout << st[i] << " " << ans <<  endl;
            ans += st.end()-upper_bound(st.begin(),st.end(),(0-st[i]));
        }
    }
    ans += (st.size()-i)*(st.size()-i-1)/2;
    cout << ans << "\n";

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