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
    vector<ll> h(n),w(n); 
    for(ll i=0; i<n; i++)
    {
        cin >> h[i];
    }

    for(ll i=0; i<n; i++)
    {
        cin >> w[i];
    }

    multimap<ll,ll> mp1, mp2;
    for(ll i=0; i<n; i++)
    {
        mp1.insert({h[i],w[i]});
        mp2.insert({w[i],h[i]});
    }

    vector<ll> final1,final2; 
    for(auto x: mp1)
    {
        // cout << x.first << " " << x.second << endl;
        final1.push_back(x.second);
    }
    for(auto x: mp2)
    {
        // cout << x.first << " " << x.second << endl;
        final2.push_back(x.second);
    }

    // for(auto x:final1)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    // for(auto x:final2)
    // {
    //     cout << x << " ";
    // }

    ll ans = 0; 
    vector<ll> temp;
    for(auto x: final1)
    {
        // cout << x << " ";
        if(temp.empty() || x > temp.back())
        {
            temp.push_back(x);
        }
        else
        {
            auto it = lower_bound(temp.begin(),temp.end(),x);
            *it = x;
        }
    }
    // cout << endl;
    ans = temp.size();
    temp.clear();
    for(auto x: final2)
    {
        // cout << x << " ";
        if(temp.empty() || x > temp.back())
        {
            temp.push_back(x);
        }
        else
        {
            auto it = lower_bound(temp.begin(),temp.end(),x);
            *it = x;
        }
    }
    // cout << endl;

    ans = min((ll)temp.size(),ans);

    cout << ans << '\n';
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