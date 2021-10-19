#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll arr[100100];
ll counts = 0;

void insert(ll x)
{
    arr[x]++;
    if(arr[x]==1) counts++;
}

void remove(ll x)
{
    arr[x]--;
    if(arr[x]==0) counts--;
}

void solve()
{
    ll n; cin >> n;
    vector<ll> vec(n);    
    set<int> st;
    for(ll i=0;i<n; i++)
    {
        cin >> vec[i];
        st.insert(vec[i]);
    } 
    ll k = st.size();
    ll tail = 0, head = -1;
    ll ans = 1e18;
    while(tail<n)
    {
        while(head+1<n && (counts<k))
        {
            head++;
            insert(vec[head]);
        }
        if(counts == k) ans = min(ans, head-tail+1);
        if(tail <= head)
        {
            remove(vec[tail]);
            tail++;
        }
        else 
        {
            tail++;
            head = tail-1;
        }
    }
    cout << ans << endl;
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