#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n,m,q;
    cin >> n >> m >> q;
    vector<ll> nos(n), partsum(n,0);
    for(ll i=0 ;i<n; i++)
    {
        cin >> nos[i];
    }
    while(m--)
    {
        ll l,r;
        cin >> l >> r;
        partsum[l-1]++;
        if(r<n)
        partsum[r]--;
    }
    // cout << partsum[0] << endl;
    for(ll i=1 ;i<n; i++)
    {
        partsum[i] += partsum[i-1];
        // cout << partsum[i] << endl;
    }
    map<ll,ll> mp;
    for(ll i=0; i<n; i++)
    {
        if(partsum[i]>0)
        {
            mp[nos[i]]=partsum[i];
        }
    }
    vector<ll> freq, element;
    ll i=0;
    for(auto x:mp)
    {
        // cout << x.first << " " << x.second << "\n";
        if(i==0)
        {
            freq.push_back(x.second);
            element.push_back(x.first);
        }
        else
        {
            freq.push_back(x.second+freq[i-1]);
            element.push_back(x.first);
        }
        i++;
    }
    // for(ll i=0; i<freq.size(); i++)
    // {
    //     cout << freq[i] << " " << element[i] << endl;
    // }
    while(q--)
    {
        ll query;
        cin >> query;
        if(query>*freq.rbegin())
        {
            cout << "-1 ";
        }
        else
        {
            ll it = lower_bound(freq.begin(),freq.end(),query)-freq.begin();
            cout << element[it] << " ";
        }
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