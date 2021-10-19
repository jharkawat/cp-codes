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

pair<ll,ii> check(string str)
{
    ll m = str.size();
    ll zero=0, one=0;
    ll sum = 0;
    for(ll i=0; i<m; i++)
    {
        if(str[i]=='0')
        {
            zero++;
            sum += one;
        } 
        else one++;
    }
    pair<ll,ii> temp = {-one,MP(zero,sum)};
    return temp;
}

bool comp(pair<ll,ii> &a, pair<ll,ii> &b)
{
    return (-1)*a.F*b.S.F > (-1)*b.F*a.S.F;
}

void solve()
{
    ll n; cin >> n;
    vector<pair<ll,ii>> st;
    for(ll i=0; i<n; i++)
    {
        string str;
        cin >> str;
        st.push_back(check(str));
    }    
    ll ans = 0, zero = 0;
    ll one;
    sort(st.begin(), st.end(), comp);
    for(auto x: st)
    {
        // cout << ans << " " << (-1)*x.F << " " << x.S.F << endl;
        ans += zero*(-1)*x.F;
        ans += x.S.S;
        zero += x.S.F;
    }
    cout << ans << '\n';
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