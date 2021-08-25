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
    priority_queue<ll, vector<ll>, greater<ll>> que;
    ll b =0;
    while(n--)
    {
        ll temp; cin >> temp;
        if(temp>b)
        {
            que.push(temp);
        }
        while(!que.empty() && b>= que.top())
        {
            que.pop();
        }
        if(que.size()>b)
        {
            b++;
        }
        cout << b << " " ;
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