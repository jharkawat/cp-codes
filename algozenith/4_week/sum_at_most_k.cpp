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
    ll vec[n];
    for(ll i=0; i<n; i++) cin >> vec[i];
    ll tail = 0, head = -1;
    ll ans = 0;
    ll sum = 0;
    while(tail<n)
    {
        while(head+1<n && (sum + vec[head+1] <= k))
        {
            head++;
            sum += vec[head];
        }
        ans += head - tail + 1;
        if(tail<= head)
        {
            sum -= vec[tail];
            tail++;
        }
        else
        {
            tail++;
            head = tail-1;
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