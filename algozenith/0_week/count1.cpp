#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
    1≤ T ≤ 10^5
    1≤ N ≤ 10^5
    1≤ Ai ≤ 10^6
    1≤ X ≤ 10^6
    It is guaranteed that the sum of N over all test cases does not exceed 10^5.
*/


void solve()
{
    ll n,x;
    cin >> n >> x;
    vector<int> nos(n);
    for(ll i=0; i<n; i++)
    {
        cin >> nos[i];
    }
    sort(nos.begin(), nos.end());
    ll ans = 0;
    for(int i=0; i<n; i++)
    {
        ans += upper_bound(nos.begin(), nos.end(), (x-nos[i]))-nos.begin();
        if((x-nos[i]) >= nos[i])
        {
            ans--;
        }
    }
    cout << ans << "\n";

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