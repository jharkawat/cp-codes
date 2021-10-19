#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

ll n,k;
ll arr[100100];
ll counts = 0;

void insert(ll x)
{
    if(arr[x] == 0)
    {
        counts++;
    }    
    arr[x]++;
}
void remove(ll x)
{
    if(arr[x] == 1)
    {
        counts--;
    }
    arr[x]--;
}

void solve()
{
    cin >> n >> k;
    vector<ll> vec(n);
    for(ll i=0; i<n; i++) cin >> vec[i];
    ll tail = 0; 
    ll head = -1;
    ll ans = 0;
    while(tail<n)
    {
        while(head+1<n && (counts<k || arr[vec[head+1]] > 0))
        {
            head++;
            insert(vec[head]);
        }
        ans += (head-tail+1);
        if(tail<=head)
        {
            remove(vec[tail]);
        }
        else
        {
            head = tail;
        }
        tail++;
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