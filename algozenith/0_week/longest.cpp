#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    ll n;
    cin >> n;
    vector<int> numbers(n);
    for(int i=0; i<n; i++)
    {
        cin>>numbers[i];
    }
    ll count = 1;
    ll ans = 2;
    ll i=1;
    while(i<n-1)
    {
        if((numbers[i-1]-numbers[i])==(numbers[i]-numbers[i+1]))
        {
            // cout << "here1 " << numbers[i] << endl;
            count++;
            if(i == n-2)
            {
                count++;
            }
            i++;
            // cout << "count: " << count << endl;
            ans = max(count,ans);
        }
        else
        {
            // cout << "here2 " << numbers[i] << endl;
            count++;
            i++;
            // cout << "count: " << count << endl;
            ans = max(count,ans);
            count = 1;
            // cout << "ans: " << ans << endl;
        }
    }
    cout << ans << endl;
}

signed main()
{
    IOS
    ll t; cin >> t;
    while(t--)
    {
        solve();
    }
}