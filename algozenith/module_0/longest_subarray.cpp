#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
1≤ T ≤ 10^5
1≤ N ≤ 10^5
1≤ Ai ≤ 10^9
It is guaranteed that the sum of N over all test cases does not exceed 105.
*/


void solve()
{
    ll n; cin >> n;
    map<ll,ll> freq;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    ll i=0; 
    ll j=0;
    ll ans = 0;
    while(i<n)
    {
        if(freq.find(arr[i]) != freq.end())
        {
            for(ll k =j; k<i; k++)
            {
                if(arr[k] != arr[i])
                {
                    freq.erase(arr[k]);
                }
                else if(arr[k] == arr[i])
                {
                    freq[arr[k]]--;
                    break;
                    j = k+1;
                }
            }
        }
        else
        {
            freq[arr[i]]++;
            ll siz = freq.size();
            ans = max(ans,siz);
        }
        i++;
    }
    cout << ans << endl;
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}