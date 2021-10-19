#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,q,k;
ll arr[100100];

bool check(ll x)
{
    if(x == n-1) return 1;
    return arr[x] > arr[x+1];
}

bool check1(ll x)
{
    return arr[x]>=k;
}

bool check2(ll x)
{
    return arr[x]<=k;
}


void solve()
{
    cin >> n >> q;
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }        
    ll lo = 0, hi = n-1, mid;
    ll ans = 0;
    while(lo<=hi)
    {
        mid = (lo+hi)/2;
        if(check(mid))
        {
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    // cout << ans << endl;
    
    while(q--)
    {
        cin >> k;
        vector<ll> sol;

        ll lo1 = 0, hi1 = ans, mid1;
        ll ans1 = -1;
        while(lo1<=hi1)
        {
            mid1 = (lo1+hi1)/2;
            if(check1(mid1))
            {
                ans1 = mid1;
                hi1 = mid1-1;
            }
            else lo1 = mid1+1;
        }
        if(arr[ans1] == k) sol.push_back(ans1+1);

        lo1 = ans+1, hi1 = n-1, mid1;
        ans1 = -1;
        while(lo1<=hi1)
        {
            mid1 = (lo1+hi1)/2;
            if(check2(mid1))
            {
                ans1 = mid1;
                hi1 = mid1-1;
            }
            else lo1 = mid1+1;
        }
        if(arr[ans1] == k) sol.push_back(ans1+1);

        for(auto x: sol)
        {
            cout << x << " ";
        }
        cout << endl;
    }
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