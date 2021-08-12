#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll h,w,n; 
    cin >> h >> w >> n;
    set<ll> len, hei;
    hei.insert(0);
    hei.insert(h);
    len.insert(0);
    len.insert(w);
    multiset<ll> max_len, max_hei;
    max_len.insert(w-0);
    max_hei.insert(h-0);
    while(n--)
    {
        char x;
        cin >> x;
        ll pos ;
        cin >> pos;
        if(x == 'H')
        {
            hei.
        }
        else
        {

        }
    }

}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}