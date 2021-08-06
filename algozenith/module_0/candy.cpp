#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
1≤ T ≤ 10^5
1≤ N ≤ 10^5
0≤ K ≤ 10^5
1≤ Ai ≤ 10^9
It is guaranteed that the sum of K over all test cases does not exceed 10^6.
*/


void solve()
{
    ll n, k;
    cin >> n >> k;
    priority_queue<ll> pqu;
    for(ll i =0; i<n; i++)   // O(nlogn)
    {
        ll p; cin >> p;
        pqu.push(p);
    }
    ll ans = 0;
    while(k--)  // O(klogn)
    {
        if(pqu.empty())
        {
            break;
        }
        ans += pqu.top();
        pqu.push((int)pqu.top()/2);
        pqu.pop();
    }
    cout << ans << "\n";
}
// O((n+k)logn)

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