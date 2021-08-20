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
    set<ll> hori,verti;
    hori.insert(0);
    hori.insert(h);
    verti.insert(0);
    verti.insert(w);
    multiset<ll> len, hei;
    hei.insert(h);
    len.insert(w);
    while(n--)
    {
        char x;
        cin >> x;
        ll pos ;
        cin >> pos;
        if(x == 'H')
        {
            hori.insert(pos);
            auto it = hori.find(pos);
            auto it1 = it, it2 =it;
            it1--; it2++;
            hei.erase(hei.find(*it2-*it1));
            hei.insert(*it2-*it);
            hei.insert(*it-*it1);
        }
        else
        {
            verti.insert(pos);
            auto it = verti.find(pos);
            auto it1 = it, it2 =it;
            it1--; it2++;
            len.erase(len.find(*it2-*it1));
            len.insert(*it2-*it);
            len.insert(*it-*it1);
        }
        cout << (*len.rbegin())*(*hei.rbegin()) << "\n";
    }

}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}