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
bool comp( ii &a, ii &b)
{
    return a.F > b.F;
}

void solve()
{
    ll n; cin >> n;
    vector<ii> st;
    vector<ll> dur(n),deadline(n);
    for(ll i=0; i<n; i++)
    {
        cin >> deadline[i];
    }    
    for(ll i=0; i<n; i++)
    {
        cin >> dur[i];
    }    

    for(ll i=0; i<n; i++)
    {
        ll a,b;
        a = dur[i];
        b = deadline[i];
        st.push_back(MP(b,a));
    }    
    sort(st.begin(), st.end(), comp);
    ll counts = 0;
    priority_queue<ll> pq;
    pq.push(-st[0].S);
    ll prev = st[0].F;
    for(ll i=1; i<n; i++)
    {
        ll dead = prev-st[i].F;
        ll dura = st[i].S;
        while(!pq.empty())
        {
            ll job = -pq.top();
            // cout << dead << " " << st[i].F  <<  " " << dura << " " <<  prev << " " << job << endl; 
            pq.pop();
            if(dead >= job)
            {
                counts++;
                dead -= job;
            }
            else
            {
                job -= dead;
                pq.push(-job);
                break;
            }
        }
        pq.push(-dura);
        prev = st[i].F;
    }
    ll dead = prev;
    while(!pq.empty() && (dead > 0))
    {
        ll job = -pq.top();
        // cout << dead << " "  <<  prev << " " << job << endl; 

        pq.pop();
        if(dead >= job)
        {
            counts++;
            dead -= job;
        }
        else break;
    }

    cout << counts << endl;
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    // solve();

    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}