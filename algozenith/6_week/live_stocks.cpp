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
    }
    ll cur = arr[0];
    ll sums = 0;
    for(ll i=1; i<n; i++)
    {
        // cout << sums << " " << arr[i] << endl;
        if(arr[i]<cur)
        {
            cur = arr[i];
        }
        else if(arr[i]>cur+k)
        {
            sums += arr[i]-cur-k;
            cur = arr[i]-k;
        }
    }
    cout << sums << endl;
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