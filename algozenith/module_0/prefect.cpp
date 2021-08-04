#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    ll q,n; 
    cin >> q >> n;
    bool flag = false;
    if(q==1)
    {
        for(ll i=1; i*i<=n; i++)
        {
            // cout << "i" << endl;
            if(i*i == n)
            {
                flag = true;
            }
        }
    }
    else if(q==2)
    {
        for(ll i=1; i*i*i<=n; i++)
        {
            if(i*i*i == n)
            {
                flag = true;
            }
        }
    }
    if(flag) 
    { 
        cout << "YES\n";
    }    
    else 
    {
        cout << "NO\n";
    }
}

// O(root(n))

signed main()
{
    IOS
    ll t; cin >> t;
    while(t--)
    {
        solve();
    }
}