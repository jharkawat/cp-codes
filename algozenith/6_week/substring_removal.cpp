#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    string str; 
    cin >> str;
    ll a,b;
    cin >> a >> b;
    ll ans = 0;
    if(a>b)
    {
        swap(a,b);
    }
    auto it = str.begin();
    while(it != str.end())
    {
        if(*it == 'a')
        {
            auto itr = it;
            itr++;
            if(itr!=str.end() && *itr == 'b')
            {
                auto rem = it;
                it--;
                str.erase(rem,rem+2);
                ans += a;
            }
            else it++;
        }
        else it++;
    }
    it = str.begin();
    while(it != str.end())
    {
        if(*it == 'b')
        {
            auto itr = it;
            itr++;
            if(itr!=str.end() && *itr == 'a')
            {
                auto rem = it;
                it--;
                str.erase(rem,rem+2);
                ans += b;
            }
            else it++;
        }
        else it++;
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