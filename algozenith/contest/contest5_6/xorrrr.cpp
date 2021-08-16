#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
const long long mod = 1000000007;

void solve()
{
    ll a,b;
    cin >> a >> b;
    if(a%2 ==0)
    {
        cout << 0;
        return;
    }
    else
    {
        bitset<44> ans(0);
        for(ll i=0; i<b; i++)
        {
            ll temp;
            cin >> temp;
            // cout << temp%mod << endl;
            bitset<44> arr(temp);
            ans = ans^arr;
        }
        // cout << ans << endl;
        ll answer = (long long)(ans.to_ullong());
        // cout << answer << endl;
        answer = answer%mod;
        cout << answer << "\n";
    }
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    solve();
}
