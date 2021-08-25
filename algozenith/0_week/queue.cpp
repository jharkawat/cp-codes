#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll q; cin >> q;
    queue<ll> que;
    while(q--)
    {
        string query;
        cin >> query;
        if(query == "add")
        {
            ll x;
            cin >> x;
            que.push(x);
        }
        else if(query == "print")
        {
            if(!que.empty())
            {
                cout << que.front() << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
        else if(query == "remove")
        {
            if(!que.empty())
            {
                que.pop();
            }
        }
    }
}

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