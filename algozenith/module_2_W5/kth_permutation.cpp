#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n,k;
vector<ll> permu;
map<ll,ll> mp;
ll ans =0;

void solve(int level)
{
    if(level == n)
    {
        ans++;
        if(ans == k)
        {
            for(ll i=0; i<n; i++)
            {
                cout << permu[i] << " ";
            }
            cout << "\n";
        }
        return;
    }
    for(auto v:mp)
    {
        if(v.second!=0)
        {
            permu.push_back(v.first);
            mp[v.first]--;
            solve(level+1);
            permu.pop_back();
            mp[v.first]++;
        }
    }



/*
    Direct appraoch with inbuilt functions.

    ll n; cin >> n;
    vector<ll> permu(n);
    for(ll i=0; i<n; i++)
    {
        cin >> permu[i];
    }
    sort(permu.begin(),permu.end());
    do{
        for(ll i=0; i<n; i++)
        {
            cout << permu[i] << " ";
        }
        cout << "\n";
    }
    while(next_permutation(permu.begin(),permu.end()));
*/

}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin >> n>>k;
    for(ll i=0; i<n; i++)
    {
        mp[i+1]++;
    }
    solve(0);
}