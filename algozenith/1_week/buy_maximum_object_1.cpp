#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> vec(n);
    for(ll i=0; i< n; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    ll i=0, sum = 0;
    while(k>=vec[i] && i<n)
    {
        sum++;
        k -= vec[i];
        i++;
    }
    cout << sum << endl;
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