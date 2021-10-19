#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll arr[1000100];
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
    ll n,k; 
    cin >> n >> k;    
    ll vec[n];
    for(ll i=0; i<n; i++)
    {
        cin >> vec[i];
        arr[vec[i]] = 0;
    } 
    counts=0;
    ll ans = 1e18;
    for(ll i=0; i<k; i++)
    {
        insert(vec[i]);
    }
    for(ll i=k; i<n; i++)
    {
        ans = min(ans,counts);
        insert(vec[i]);
        remove(vec[i-k]);
    }
    ans = min(ans,counts);
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