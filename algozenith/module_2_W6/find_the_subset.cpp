#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n;
    cin>>n;
    map<ll,ll> mp;
    mp[0]=1;
    ll ans = 0;
    vector<ll> vec(n);
    for(ll i=0; i<n; i++)
    {
        cin >> vec[i];
    }

    for(ll i=0; i<n; i++)
    {
        ans += vec[i];
        ans = ans%n;
        if(mp.find(ans) != mp.end())
        {
            cout << "YES" << "\n";
            return;
        }
        else
        {
            mp[ans] = 1;
        }
    }
    
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