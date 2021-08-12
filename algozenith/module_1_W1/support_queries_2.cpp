#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


struct myprio{
    multiset<ll> hi,lo;
    ll sum_hi=0;
    ll k;
    void init(ll k)
    {
        this->k = k;
    }
    void insert(ll x)
    {
        if(hi.size()<k)
        {
            hi.insert(x);
            sum_hi += x;
        }
        else 
        {
            if(x>*hi.begin())
            {
                hi.insert(x);
                sum_hi += x;
            }
            else
            {
                lo.insert(x);
            }
        }
    }
    void remove(ll x)
    {
        if(hi.find(x)!=hi.end())
        {
            hi.erase(hi.find(x));
            sum_hi -= x;
        }
        else if(lo.find(x)!=lo.end())
        {   
            lo.erase(lo.find(x));
        }
    }
    ll get_sum()
    {
        rebalance();
        return sum_hi;
    }
    void rebalance()
    {
        if(hi.size()<k)
        {
            while(hi.size()<k && lo.size()!=0)
            {
                ll temp = *lo.rbegin();
                hi.insert(temp);
                sum_hi += temp;
                lo.erase(prev(lo.end()));
            }
        }
        else if(hi.size()>k)
        {
            while(hi.size()>k)
            {
                ll temp = *hi.begin();
                lo.insert(temp);
                sum_hi -= temp;
                hi.erase(hi.begin());
            }
        }
    }

};

void solve()
{
    ll q,k;
    cin >> q >> k;
    myprio priority;
    priority.init(k);
    while(q--)
    {
        ll n; cin >> n;
        if(n==1)
        {
            ll x; cin>>x;
            priority.insert(x);
        }
        else if( n==2)
        {
            ll x; cin>>x;
            priority.remove(x);
        }
        else if(n==3)
        {
            char ch; cin>> ch;
            cout << priority.get_sum() << endl;
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

    solve();
}