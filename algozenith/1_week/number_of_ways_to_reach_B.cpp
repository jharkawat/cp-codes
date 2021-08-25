#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

const ll mod = 1e9 + 7;
ll arr[200100];

void cal_fact()
{
    ll ans = 1;
    for(int i=1; i<200100; i++)
    {
        ans = ((ans%mod)*(i%mod))%mod;
        arr[i] = ans;
    }
}

ll inverse_cal(ll a, ll b)
{
    ll ans =1;
    while(b)
    {
        if(b%2 ==1)
        {
            ans = ((ans%mod)*(a%mod))%mod;
        }
        a = ((a%mod)*(a%mod))%mod;
        b = b/2;
    }
    return ans;
}

void solve()
{
    ll m,n;
    cin >> m >> n;
    ll mplusn = arr[m+n];
    ll inv = ((arr[n]%mod)*(arr[m]%mod))%mod;
    ll inv_ans = inverse_cal(inv,mod-2);
    cout << ((mplusn%mod)*(inv_ans%mod))%mod << "\n";
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    
    cal_fact();
    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}