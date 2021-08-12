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
    ll ans =0;
    cin >> n >> m;
    map<ll,set<pair<ll,ll>>> mp1, mp2;
    while(n--)
    {
        ll a,b;
        cin >> a >> b;
        mp1[a*b].insert({a,b});
    }
    while(m--)
    {
        ll a,b;
        cin >> a >> b;
        mp2[a*b].insert({a,b});
    }
    for(auto x : mp1)
    {
        while(!x.second.empty() && (mp2.find(x.first) != mp2.end()))
        {
            if(!mp2[x.first].empty())
            {
                ans++;
                x.second.erase(x.second.begin());
                mp2[x.first].erase(mp2[x.first].begin());
            }
        }
    }
    cout << ans << endl;

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