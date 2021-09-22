#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

#define F first
#define S second
#define MP make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll k;
struct festival
{
    multiset<ll> lo, hi;
    ll sum = 0;
    void insert(ll x)
    {
        hi.insert(x);
        sum += x;
        if(hi.size()>k)
        {
            auto it = hi.begin();
            lo.insert(*it);
            sum -= *it;
            hi.erase(hi.begin());
        }
        // if(hi.size()<k)
        // {
        //     hi.insert(x);
        //     sum += x;
        // }
        // else
        // {
        //     if(x > *hi.begin())
        //     {
        //         auto it = hi.begin();
        //         sum -= *it;
        //         lo.insert(*it);
        //         hi.erase(hi.find(*it));
        //         hi.insert(x);
        //         sum += x;
        //     }
        //     else
        //     {
        //         lo.insert(x);
        //     }
        // }
    }

    void remove(ll x)
    {
        if(lo.find(x) != lo.end())
        {
            lo.erase(lo.find(x));
        }
        else
        {
            hi.erase(hi.find(x));
            sum -= x;
            if(!lo.empty())
            {
                ll it = *lo.rbegin();
                hi.insert(it);
                sum += it;
                lo.erase(lo.find(it));
            }
        }
        // if(x >= *hi.begin())
        // {
        //     hi.erase(hi.find(x));
        //     sum -= x;
        //     if(!lo.empty())
        //     {
        //         auto it = lo.rbegin();
        //         hi.insert(*it);
        //         sum += *it;
        //         lo.erase(lo.find(*it));
        //     }
        // }
        // else
        // {
        //     lo.erase(lo.find(x));
        // }
    }

    ll maxi()
    {
        return sum; 
    }
};


ll solve()
{
    ll n ,d;
    cin >> d >> n >> k;
    festival fs; 
    set<ii> st;
    st.clear();
    ll ans = -1e18;
    for(ll i=0; i<n; i++)
    {
        ll h,s,e;
        cin >> h >> s >> e;
        st.insert(MP(s,h));
        st.insert(MP(e+1,-h));
        // cout << h << " " << s << " " << e << endl;
    }
    ll prev = -1;
    for(auto v : st)
    {
        // (1,4),(1,7),(1,-6)  ==  5
        // (2,5) 
        // cout << v.F << " " << v.S << " " << ans << " " << fs.maxi() << endl;
        if(prev != v.F)
        {
            ans = max(ans,fs.maxi());
        }
        ll type = v.S;
        if(type < 0)
        {
            fs.remove(-type);
        }
        else
        {
            fs.insert(type);
        }
        prev = v.F;
    }
    ans = max(ans,fs.maxi());
    return ans;
}

signed main()
{
    IOS

    ll t; cin >> t; 
    ll ans; 
    for(ll i=1; i<=t; i++)
    {
        ans = solve();
        cout << "Case #" << i << ": " << ans << "\n";
    }
}