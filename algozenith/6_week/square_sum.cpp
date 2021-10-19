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
    ll mean = 0; 
    ll A[n]; 
    for(ll i=0; i<n; i++){
        cin >> A[i];
        mean += A[i];
    } 
    ll avg = ceil(mean/n);
    mean /= n;
    ll ans = 0;
    ll ans2 = 0;
    for(ll i=0; i<n; i++)
    {
        ans2 += (A[i]-avg)*(A[i]-avg);
        ans += (A[i]-mean)*(A[i]-mean);
    } 
    cout << min(ans,ans2) << endl;
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