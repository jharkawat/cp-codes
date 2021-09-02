#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n;
    cin >> n;
    ll ans = 1;
    for(ll i=0; i<n ;i++)
    {
        if(!i)
        {
            ll m;
            cin >> m;
            for(ll j=0; j<m; j++)
            {
                ll temp; cin >> temp;
                ans *= temp;
            }
        }
        else
        {
            ll m;
            cin >> m;
            ll no = 1;
            for(ll j=0; j<m; j++)
            {
                ll temp; cin >> temp;
                no *= temp;
            }
            ans = __gcd(ans,no);
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

    solve();

    // ll t; cin >> t; 
    // while(t--)
    // {
    //     solve();
    // }
}