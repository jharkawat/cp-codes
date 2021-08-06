#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
add x - add element x at the top of Priority Queue
remove - delete top element of the Priority Queue, if Priority Queue is not empty
print - print the element at top of the Priority Queue, if Priority Queue is not empty, otherwise print 0
*/


void solve()
{
    ll q; cin >> q;
    priority_queue<ll> prq;
    while(q--)
    {
        string qr;
        cin >> qr;
        if(qr == "add"){
            ll x; cin >> x;
            prq.push(x);
        }
        else if(qr == "remove"){
            if(!prq.empty())
            {
                prq.pop();
            }
        }
        else if(qr == "print"){
            if(!prq.empty())
            {
                cout << prq.top() <<"\n";
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