#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n; cin >> n;
    stack<ll> factors;
    for(int i=1; i*i<=n; i++)
    {
        if(n%i == 0)
        {
            cout << i << " ";
            if(i*i!=n)
            factors.push(n/i);
        }
    }
    while(!factors.empty())
    {
        cout << factors.top() << " ";
        factors.pop();
    }
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    
    solve();
}