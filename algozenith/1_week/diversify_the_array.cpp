#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n,k;
    cin >> n >> k;
    map<ll,ll> elements;
    for(ll i=0; i<n; i++)
    {
        ll temp;
        cin >> temp;
        elements[temp]++;
    }
    // for(auto x: elements)
    // {
    //     cout << x.first << " " << x.second << "\n";
    // }
    priority_queue<pair<ll,ll>> freq;
    for(auto x: elements)
    {
        freq.push({x.second,x.first});
    }
    ll ans = 0;
    while(!freq.empty())
    {
        ll nos = freq.top().first;
        if(nos > 1 && k != 0)
        {
            ans += n-1;
            n -= 1;
            nos -= 1;
            k--;
            freq.push({nos,freq.top().second});
        }
        else if(nos > 1)
        {
            ans += nos*(n-nos);      
            n -= nos;      
        }
        else
        {
            ans += n-1;
            n -= nos;
        }
        freq.pop();
        // cout << x.first << " " << ans << endl;
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
    
    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}