#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

const ll mod = 1e9 + 7;

void solve()
{
    int n,q;
    cin >> n >> q;
    vector<ll> arr(n), prefix(n+1);
    prefix[0]=0;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        prefix[i+1] = prefix[i]+arr[i];
    }
    while(q--)
    {
        ll l,r;
        cin>> l >>r;
        cout << (prefix[r]-prefix[l-1]+mod)%mod << "\n";
    }
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    

    solve();
    
}