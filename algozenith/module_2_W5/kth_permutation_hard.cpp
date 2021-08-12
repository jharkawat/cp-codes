#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

int fact(ll n)
{
    int i=1;
    ll ans = 1;
    while(n)
    {
        n /= i;
        ans *= i;
        i++;
    }
    return ans;
}

void solve()
{
    ll n,k; cin >> n >> k;
    vector<ll> arr(100100);
    for(ll i=0; i<n; i++)
    {
        arr[i] = i+1;
    }
    while(k>1)
    {
        ll change = fact(k);
        ll val = k/change;
        k = k%change;
        cout << change << " " << k << " " << val << "\n";
        
    }

}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    // ll t; cin >> t; 
    // while(t--)
    // {
    //     solve();
    // }
}