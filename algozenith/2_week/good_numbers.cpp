#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

long long const N = 1000100;

void solve()
{
    // cout << "here \n"; 
    ll n,k,q;
    cin >> n >> k >> q;
    vector<ll> arr(N,0);
    for(ll i=0; i<n; i++)
    {
        ll l,r;
        cin >> l >>r;
        arr[l]++;
        arr[r+1]--;
    }
    // cout << "here1 \n"; 
    for(ll i=1; i<N; i++)
    {
        arr[i] += arr[i-1];
    }
    // cout << "here2 \n"; 
    for(ll i=1; i<N; i++)
    {
        arr[i] = (arr[i]>=k);
    }
    for(ll i=1; i<N; i++)
    {
        arr[i] += arr[i-1];
    }
    // cout << "here4 \n"; 
    while(q--)
    {
        ll l,r;
        cin >> l >> r;
        cout << arr[r]-arr[l-1]<< "\n";
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