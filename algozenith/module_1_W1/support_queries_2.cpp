#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


struct myprio{
    multiset<ll> hi,lo;
    ll sum=0;
    ll k;
    void init(ll k)
    {
        this->k = k;
    }
    void insert(ll x)
    {
        hi.insert(x);
        sum += x;
        if((ll)hi.size()>k)
        {
            ll temp = *(hi.begin());
            lo.insert(temp);
            sum -= temp;
            hi.erase(hi.find(temp));
        }

        return;
    }
    void remove(ll x)
    {
        if(hi.count(x))
        {
            hi.erase(hi.find(x));
            sum -= x;
            if((ll)hi.size()<k)
            {
                if((ll)lo.empty())
                {
                    return;
                }
                ll temp = *(lo.rbegin());
                hi.insert(temp);
                sum += temp;
                lo.erase(lo.find(temp));
            }
        }
        else if(lo.count(x))
        {   
            lo.erase(lo.find(x));
        }
        return;
    }
    ll get_sum()
    {
        return sum;
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
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    solve();
}