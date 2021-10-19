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
    deque<ll> dq;
    ll ans = 1e18;
    for(ll i=0; i<n; i++) cin >> arr[i];
    for(ll i=1; i<n; i++)
    {
        if(i<(n-k))
        {
            ll temp = arr[i]-arr[i-1];
            while(!dq.empty() && dq.back()<temp)
            {
                dq.pop_back();
            }
            dq.push_back(temp);
            ans = min(ans,dq.front());
            // cout << "i " << i << endl;
            // for(auto x:dq)
            // {
            //     cout << x << " ";
            // }
            // cout << endl;
        }
        else
        {
            ll rem = arr[i-(n-k)+1]-arr[i-(n-k)];
            if(dq.front() == rem) dq.pop_front();
            ll temp = arr[i]-arr[i-1];
            while(!dq.empty() && dq.back()<temp)
            {
                dq.pop_back();
            }
            dq.push_back(temp);
            ans = min(ans,dq.front());
            // cout << rem << endl;
            // cout << "ii " << i << endl;
            // for(auto x:dq)
            // {
            //     cout << x << " ";
            // }
            // cout << endl;
        }
    }
    cout << ans << endl;
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