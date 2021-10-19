#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n; cin >> n;
    vector<ii> inter(n);
    for(ll i=0; i<n; i++)
    {
        cin >> inter[i].second;
        cin >> inter[i].first;
    }    
    sort(inter.begin(), inter.end());
    ll last = -1e18, points = 0;
    for(auto x: inter)
    {
        ll l = x.second;
        ll r = x.first;
        if(l>last)
        {
            last = r;
            points++;
        }
    }
    cout << points << '\n';
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