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
    ll vec[n];
    for(ll i=0; i<n; i++) cin >> vec[i];
    sort(vec,vec+n);
    ll mid = 1;
    ll diff = 1e18;
    ll sum =0;
    for(mid = 1; mid<n-1; mid++)
    {
        ll left = 0, right = n-1;
        while(left<mid || right>mid)
        {
            sum = vec[left] + vec[mid] + vec[right];
            diff= min(diff,abs(k-sum));
            if(k>sum)
            {
                if(left+1<mid)
                {
                    left++;
                }
                else break;
            }
            else
            {
                if(right-1>mid)
                {
                    right--;
                }
                else break;

            }
        }
    }
    cout << diff << endl;
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