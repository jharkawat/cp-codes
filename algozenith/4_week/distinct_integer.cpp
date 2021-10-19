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
    ll n,k; cin >> n >> k;
    vector<ll> vec(n);    
    for(ll i=0;i<n; i++)
    {
        cin >> vec[i];
        arr[vec[i]] = 0;
    } 
    counts = 0;
    ll tail = 0, head = -1;
    ll ans = 0;
    while(tail<n)
    {
        // cout << vec[tail] << " " << vec[head+1] << endl;
        while(head+1<n && (counts<k))
        {
            // cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << " " << arr[5] << "\n";  
            // cout << vec[tail] << " " << vec[head+1] << " " << counts << " " << arr[vec[head]] << endl;
            head++;
            insert(vec[head]);
            if(counts == k) ans++;
        }
        ll temp = head;
        while(counts == k && temp+1<n && arr[vec[temp+1]] > 0)
        {
            ans++;
            temp++;
        }
        if(tail <= head)
        {
            remove(vec[tail]);
            if(counts == k) ans++;
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