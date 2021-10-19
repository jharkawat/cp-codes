#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

#define F first
#define S second
#define MP make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
bool comp(ii &a, ii &b)
{
    return (a.S-a.F) > (b.S-b.F);
}

void solve()
{
    ll n; cin >> n;
    vector<ii> st;
    for(ll i=0; i<n; i++)
    {
        ll a,b;
        cin >> a >> b;
        st.push_back(MP(b,a));
    }
    sort(st.begin(), st.end(), comp);
    ll ans=0;
    for(auto it = st.begin(); it != st.end(); it++)
    {
        ans += it->F;
    }
    auto it = st.rbegin();
    ans += it->S;
    ans -= it->F;
    ll temp = ans;
    for(auto it = st.begin(); it != st.end(); it++)
    {
        if(ans < it->S)
        {
            temp += it->S-ans;
        }
        ans -= it->F;
    }

    cout << temp << '\n';
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
    while(t--)
    {
        solve();
    }
}