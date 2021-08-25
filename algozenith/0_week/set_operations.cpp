#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n,m;
    cin >> n >> m;
    set<ll> a,b,minus,intersection;
    for(ll i=0; i<n; i++)       //O(2nlogn)
    {
        ll p; cin >> p;
        a.insert(p);
        minus.insert(p);
    }
    for(ll i=0; i<m; i++)       //O(mlogm)
    {
        ll p; cin >> p;
        b.insert(p);
    }

    auto it0 = b.begin();
    while(it0 != b.end())      //O(mlogm)
    {
        if(minus.find(*it0) != minus.end())
        {
            intersection.insert(*it0);
            minus.erase(*it0);
            it0++;
        }
        else
        {
            it0++;
        }
    }

    vector<ll> unions;
    auto it = minus.begin();
    auto it2 = b.begin();
    while(it != minus.end() || it2 != b.end())   // O((m+n)
    {
        if(it != minus.end())
        {
            unions.push_back(*it);
            it++;
        }
        if(it2 != b.end())
        {
            unions.push_back(*it2);
            it2++;
        }
    }
    sort(unions.begin(), unions.end());         // O(slogs)
    for(auto x : unions)         // O(logs)
    {
        cout << x << " ";
    }
    cout << "\n";
    for(auto x : intersection)      // O(logs)
    {
        cout << x << " ";
    }
    cout << "\n";
    for(auto x : minus)             // O(logs)
    {
        cout << x << " ";
    }
    cout << "\n";

}


// O(slogs)

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