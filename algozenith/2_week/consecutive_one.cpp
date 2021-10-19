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
    ll arr[n];
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
        arr[i] ^=1;
    }    
    ll prefi[n+1];
    prefi[0]=0;
    for(ll i=0; i<n; i++)
    {
        prefi[i+1] = prefi[i]+arr[i];
    }
    ll i=0, j=1;
    ll ans = 0; 
    while(j<=n)
    {
        if((prefi[j]-prefi[i])<=k)
        {
            j++;
        }
        else
        {
            ans = max(ans,(j-i-1));
            i++;
        }
    }
    ans = max(ans,(j-i-1));
    cout << ans << '\n';
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