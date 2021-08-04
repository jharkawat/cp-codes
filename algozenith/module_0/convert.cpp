#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

string convert(ll base, string num, ll req_base)
{
    // cout << "yes2" << endl;
    string converted;
    ll decimal = 0;
    ll pos = num.size()-1;
    ll pow = 1;
    for(ll i = pos; i>=0; i--)
    {
        int c = num[i];
        if(isupper(c))
        {
            c -= 55;
        }
        else
        {
            c -= 48;
        }
        decimal += c*pow;
        pow *= base;
    }
    // cout << decimal << endl;
    // cout << "yes3" << endl;
    converted.clear();
    while(decimal>0)
    {
        int mod = decimal%req_base;
        // cout << mod << endl;
        string ans;
        // cout << ans << endl;
        if(mod>9)
        {
            ans = 55+mod;
            // cout << ans << endl;
        }
        else 
        {
            ans = 48+mod;
        }
        converted = ans + converted;
        decimal /= req_base;
    }
    // cout << "yes4" << endl;

    // cout << converted << endl;
    return converted;
}


void solve()
{

    ll a,b;
    string n;
    cin >> n;
    cin >> a >> b;
    // cout << "yes" << endl;
    string ans = convert(a,n,b);
    cout << ans << "\n";
}

signed main()
{
    IOS
    ll t; cin >>t;
    while(t--)
    {
        solve();
    }
}