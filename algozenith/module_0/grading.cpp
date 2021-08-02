#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    ll m,f,r;
    cin >> m >> f >> r;
    char ans = 'F';
    if((m+f)>=80) ans = 'A';
    else if((m+f)>=65) ans = 'B';
    else if((m+f)>=50) ans = 'C';
    else if((m+f)>=30) {
        ans = 'D';
        if(r>=50)
        {
            ans = 'C';
        }
    }
    else ans = 'F';
    if(m == -1 || f == -1)
    {
        ans = 'F';
    }
    cout << ans << "\n";
}

signed main()
{
    IOS
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}