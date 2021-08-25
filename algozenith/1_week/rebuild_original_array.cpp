#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n; cin>>n;
    ll temp = pow(2,n);
    multiset<ll> mset;
    while(temp--)
    {
        ll p; cin >> p;
        mset.insert(p);
    }
    mset.erase(0);
    vector<ll> ans;
    while(ans.size()<n)
    {
        if(ans.empty())
        {
            ll temp = *mset.begin();
            ans.push_back(temp);
            mset.erase(mset.find(temp));
        }
        // else
        // {
        //     ll temp = *mset.begin();
        //     for(auto x:ans)
        //     {
        //         mset.erase(mset.find(x+temp));
        //     }
        //     ans.push_back(temp);
        // }
    }
    for(auto x:ans)
    {
        cout << x << " ";
    }
    cout << "\n";
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