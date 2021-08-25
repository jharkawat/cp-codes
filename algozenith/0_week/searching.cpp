#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    ll n,q;
    cin >> n >> q;
    vector<ll> numbers(n);
    for(int i =0; i<n; i++)
    {
        cin >> numbers[i];
    }
    while(q--)
    {
        ll a,b;
        cin >> a >> b;
        if(a==1 && (lower_bound(numbers.begin(),numbers.end(),b) != numbers.end()))
        {
            cout << *lower_bound(numbers.begin(),numbers.end(),b) << " " ; 
        }
        else if(a==2 && (upper_bound(numbers.begin(),numbers.end(),b) != numbers.end()))
        {
            cout << *upper_bound(numbers.begin(),numbers.end(),b) << " " ; 
        }
        else if(a==3 && (upper_bound(numbers.begin(),numbers.end(),b) != numbers.end()))
        {
            cout << (upper_bound(numbers.begin(),numbers.end(),b)-numbers.begin()) << " " ; 
        }
        else if(a==4 && (lower_bound(numbers.begin(),numbers.end(),b) != numbers.end()))
        {
            cout << (lower_bound(numbers.begin(),numbers.end(),b)-numbers.begin()) << " " ; 
        }
        else
        {
            cout << -1 << " ";
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