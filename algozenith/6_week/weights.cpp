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
    ll arr[n];
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }    
    sort(arr, arr+n);
    ll curr_ans = 1;
    for(auto x: arr)
    {
        if(curr_ans < x)
        {
            break;
        }
        else
        {
            curr_ans = curr_ans + x;
        }
    }
    cout << curr_ans << endl;
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