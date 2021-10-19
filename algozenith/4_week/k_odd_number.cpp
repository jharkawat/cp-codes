#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

multiset<ll> st;
ll sum = 0;
void insert(ll x, ll y)
{
    st.insert(x);
    if(y%2 == 1)
    {
        sum++;
    }
}

void remove(ll x, ll y)
{
    if(y%2 == 1)
    {
        sum--;
    }
    if(!st.empty()) st.erase(st.find(x));
}

void solve()
{ 
    // cout << "here" << endl;
    ll n,k,d;
    cin >> n >> k >> d;
    ll vec[n];
    for(ll i=0; i<n; i++) cin >> vec[i];

    ll tail = 0;
    ll head = -1;
    ll pref[n];
    ll ans = -1e18;

    for(ll i=0; i<n ; i++)
    {
        if(i==0) pref[i] = vec[i];
        pref[i] = vec[i]+pref[i-1];
    }

    while(tail<n)
    {
        while(head+1<n && (sum<k || vec[head+1]%2 == 0))
        {
            head++;
            insert(pref[head],vec[head]);
        }
        if(tail!=0)
        {
            auto it = st.upper_bound(d+pref[tail-1]);
            if(it!=st.begin())
            {
                it--;
                ll temp = *it;
                ans = max(ans,(temp-pref[tail-1]));
            }
        }
        else
        {
            auto it = st.upper_bound(d);
            if(it!=st.begin())
            {
                it--;
                ll temp = *it;
                ans = max(ans,(temp));
            }
        }

        if(tail<=head)
        {
            remove(pref[tail],vec[tail]);
            tail++;
        }
        else
        {
            tail++;
            head = tail-1;
        }
    }
    if(ans == -1e18)
    {
        cout << "IMPOSSIBLE\n";
    }
    else cout << ans << endl; 
    
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