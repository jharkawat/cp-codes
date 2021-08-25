#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
insertback x - add element x at the end of deque
eraseback - delete end element of the queue, if queue is not empty
insertfront x - add element x at the front of deque
erasefront - delete front element of the queue, if queue is not empty
printfront - print element at front of the queue, if queue is not empty, otherwise print 0
printback - print element at back of the queue , if queue is not empty, otherwise print 0
print x - print the x-th character of the vector, if it exists, otherwise print 0. (0-indexing)
*/


void solve()
{
    ll q; cin >> q;
    deque<ll> dq;
    while(q--)
    {
        string str;
        cin >> str;
        if(str == "insertback")
        {
            ll x; cin >> x;
            dq.push_back(x);
        }
        else if(str == "eraseback")
        {
            if(!dq.empty())
            {
                dq.pop_back();
            }
        }
        else if(str == "insertfront")
        {
            ll x; cin >> x;
            dq.push_front(x);
        }
        else if(str == "erasefront")
        {
            if(!dq.empty())
            {
                dq.pop_front();
            }
        }
        else if(str == "printfront")
        {
            if(!dq.empty())
            {
                cout << dq.front() << "\n";
            }
        }
        else if(str == "printback")
        {
            if(!dq.empty())
            {
                cout << dq.back() << "\n";
            }
        }
        else if(str == "print")
        {
            ll x; cin >> x;
            if(x<(int)dq.size()) 
            {
                cout << dq[x] << endl;
            }
            else
            {
                cout << 0 << endl;
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