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
    cin >>n >> m;
    vector<ll> vec(n);
    for(int i=0; i<n; i++)
    {
        cin >> vec[i];
    }
    if(n>m)
    {
        cout << "0" << "\n";
    }
    else
    {
        ll ans =1;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                ans *= abs(vec[i]-vec[j]);
                ans = ans%m;
            }
        }
        cout << ans%m << endl;
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