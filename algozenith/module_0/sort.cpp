#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool comparator(pair<string,int> a, pair<string,int> b)
{
    return a.second < b.second;
}

void solve()
{
    ll n; cin >> n;
    vector<pair<string,ll>> students;
    for(ll i=0; i<n; i++)
    {
        string name;
        ll roll;
        cin >> name >> roll;
        pair<string,ll> temp = make_pair(name,roll);
        students.push_back(temp);
        sort(students.begin(),students.end(),comparator);
    }
    for(auto x : students)
    {
        cout << x.first << " " << x.second << "\n";
    }
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