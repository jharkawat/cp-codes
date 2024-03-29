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


void solve()
{
    ll n; cin >> n;
    set<ii> st;
    vector<ll> rating;
    for(ll i=0; i<n; i++)
    {
        ll temp ; cin >> temp;
        st.insert(MP(temp,i));
        rating.push_back(temp);
    }   
    vector<ll> ans(n,1);
    for(auto it = st.begin(); it != st.end(); it++)
    {
        ii temp = *it;
        ll rat = temp.F;
        ll pos = temp.S;
        if(pos>0 && rating[pos-1]<rat)
        {
            ans[pos] = max(ans[pos],ans[pos-1]+1);
        }
        else if(pos<n-1 && rating[pos+1]<rat)
        {
            ans[pos] = max(ans[pos],ans[pos+1]+1);
        }
    }
    ll sum = 0;
    for(auto x: ans)
    {
        sum += x;
    }
    cout << sum << endl;
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