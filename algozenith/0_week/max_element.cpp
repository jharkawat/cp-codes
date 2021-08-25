#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }   
    // cout << "here" << endl;
    // for(auto x: arr)
    // {
    //     cout << x << endl;
    // }

    multiset<ll> st;
    for(ll i=0; i<n; i++)
    {
        if(i<k)
        {
            // cout << "here 2 " << endl;

            st.insert(arr[i]);
            if(i==k-1)
            {
                // cout << "here 3" << endl;
                auto it = st.end();
                it--;
                cout << *it << " ";            }
        }
        else
        {
            // cout << "here 4" << endl;
            st.insert(arr[i]);
            st.erase(st.find(arr[i-k]));
            auto it = st.end();
            it--;
            cout << *it << " ";
        }
    }
    cout << endl;
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