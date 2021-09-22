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
    vector<ll> vec(n);
    ll sum =0; 
    ll maxi = -1;
    for(ll i=0; i<n; i++)    
    {
        cin >> vec[i];
        sum += vec[i];
        maxi = max(maxi,vec[i]);
    }
    sum -= 2*maxi;
    if(sum<=0)
    {
        cout << -1*sum << '\n';
    }
    else
    {
        if(sum%2) cout << "1\n";
        else cout << "0\n";
    }
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