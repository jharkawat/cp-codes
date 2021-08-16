#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n,x; 
    cin >> n >> x;
    vector<ll> vec(n);
    for(ll i=0; i<n ; i++)
    {
        cin >> vec[i];
    }
    set<ll> cplusd;
    cplusd.insert(vec[n-1]+vec[n-2]);
    for(ll j=n-3; j>0; j--)
    {
        for(ll i=0; i<j; i++)
        {
            ll sum = vec[j]+vec[i];
            if(cplusd.find(x-sum) != cplusd.end())
            {
                cout << "YES" << '\n';
                cout << j << " " << i << endl;
                return; 
            }
        }
        for(ll k=j+1; k<n; k++)
        {
            cplusd.insert(vec[j]+vec[k]);
        }
    }
    cout << "NO" << endl;
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