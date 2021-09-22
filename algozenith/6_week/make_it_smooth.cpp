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
    ll maxi = -1;
    ll mini = 1e18; 
    ll sum = 0; 
    ll prev = 0;
    for(ll i=0; i<n; i++)    
    {
        ll temp; 
        cin >> temp;
        if(prev>temp)
        {
            sum += prev-temp;
        }
        prev = temp;
    }
    cout << sum << '\n';
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