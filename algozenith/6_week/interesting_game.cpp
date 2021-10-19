#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

#define MP make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

bool comp(ii &a, ii &b)
{
    return (a.F+a.S) > (b.F+b.S);
}

void solve()
{
    ll n; cin >> n;
    ll a[n], b[n];
    vector<ii> nos;
    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=0; i<n; i++) cin >> b[i];
    for(ll i=0; i<n; i++) nos.push_back(MP(a[i],b[i]));
    sort(nos.begin(), nos.end(), comp);
    ll p1=0, p2=0;
    bool flag = true;
    for(auto x: nos)
    {
        if(flag)
        {
            p1 += x.F;
            flag = false;
        }
        else
        {
            p2 += x.S;
            flag = true;
        }
    }
    if(p1>p2) cout << "Alice\n";
    else if(p1 == p2) cout << "Tie\n";
    else cout << "Bob\n";

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