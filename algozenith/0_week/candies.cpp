#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
    Constraints

    1≤ T ≤ 10^5
    1≤ N, B ≤ 10^5
    1≤ Ai ≤ 1000
    It is guaranteed that the sum of N over all test cases does not exceed 105.
*/

void solve()
{
    ll n,b;
    cin >> n >> b;
    ll count = 0;
    vector<int> prices(n);
    for(ll i=0; i<n; i++)
    {
        cin >> prices[i];
    }
    sort(prices.begin(), prices.end());
    ll i =0;
    while(b>=prices[i] && i<n)
    {
        b-=prices[i];
        count++;
        i++;
    }
    cout << count << "\n";
}

//O(nlogn)

signed main()
{
    IOS
    ll t; cin >> t;
    while(t--)
    {
        solve();
    }
}