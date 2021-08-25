#include<bits/stdc++.h>
using namespace std;
using ll = int;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

void print(multiset<ll> st)
{
    for(auto s:st)
    {
        cout << s << " ";
    }
    cout << "\n";
}

void solve()
{
    multiset<ll> mset;
    ll n; cin >> n;
    ll sum =0;
    while(n--)
    {
        // cout << "n :" << n << "\n";
        ll qry;
        cin >> qry;
        if(qry == 1){
            ll temp ;
            cin >> temp;
            mset.insert(temp);
            sum += temp;
            // print(mset);
        }
        else if(qry == 2){
            ll temp ;
            cin >> temp;
            if (mset.find(temp) != mset.end()) {
                mset.erase(mset.find(temp));
            	sum -= temp;
            }
            // print(mset);
        }
        else if(qry == 3){
            char ch;
            // cout << "qry: " << qry << " ";
            cin >> ch;
            if(!mset.empty()) cout << *mset.begin() << "\n";
            else cout << "-1" << "\n";
            // print(mset);
        }
        else if(qry == 4){
            char ch;
            // cout << "qry: " << qry << " ";
            cin >> ch;
            if(!mset.empty())
            {
                auto it = mset.end();
                it--;
                cout << *it << "\n";
            } 
            else cout << "-1" << "\n";
            // print(mset);
        }
        else if(qry == 5){
            char ch;
            // cout << "qry: " << qry << " ";
            cin >> ch;
            if(!mset.empty()) cout << sum << "\n";
            else cout << "0" << "\n";
            // print(mset);
        }

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