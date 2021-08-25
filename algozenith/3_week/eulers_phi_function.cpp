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
    ll ans = n, x=n;
    for(int i=2; i*i<=x; i++)
    {
        if(x%i == 0)
        {
            ans -= ans/i;
            while(x%i==0)
            {
                x /= i;
            }
        }
    }
    if(x>1)
    {
        ans -= ans/x;
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
    
    solve();
}