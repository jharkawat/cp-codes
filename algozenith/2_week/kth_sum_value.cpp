#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,m,k;
ll A[1001000],B[1001000];

bool check(ll x)
{
    ll ele = 0;
    for(ll i=0; i<n; i++)
    {
        ele += upper_bound(B, B + m, x-A[i]) - B;
    }
    return ele >= k;
}

void solve()
{
    cin >> n >> m >> k;
    for(ll i=0; i<n; i++)
    {
        cin >> A[i];
    }
    for(ll i=0; i<m; i++)
    {
        cin >> B[i];
    }
	if(n>m)
    {
        swap(A,B);
        swap(n,m);
    }
    sort(A, A+n);
    sort(B, B+m);
    ll lo = (A[0]+B[0]);
    ll hi = (A[n-1]+B[m-1]);
    ll ans = lo;
    while(lo<=hi)
    {
        // cout << ans << endl;
        ll mid = (lo+hi)/2;
        if(check(mid))
        {
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    cout << ans << "\n";
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