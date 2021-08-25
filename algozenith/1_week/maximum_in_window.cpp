#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
1 ≤ T ≤ 10^5
1 ≤ K ≤ N ≤ 10^5
-10^9 ≤ Ai ≤ 10^9
Sum of N over all test cases ≤ 5 * 10^5.
*/

struct maximum{
    deque<ll> dq;

    void insert(ll x)
    {
        while(!dq.empty() && dq.back()<x)
        {
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void remove(ll x)
    {
        if(dq.front() == x)
        {
            dq.pop_front();
        }
    }
    ll getmax()
    {
        return dq.front();
    }
};


void solve()
{
    ll n,k;
    cin >> n >> k;
    maximum mydq;
    ll arr[n];
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
        if(i==k-1)
        {
            mydq.insert(arr[i]);
            cout << mydq.getmax() << " ";
        }
        else if(i>=k)
        {
            mydq.insert(arr[i]);
            mydq.remove(arr[i-k]);
            cout << mydq.getmax() << " ";
        }
        else
        {
            mydq.insert(arr[i]);
        }
    }
    cout << "\n";

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