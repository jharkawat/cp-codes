#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    double x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double ecl, man;
    man = abs(x1-x2)+abs(y1-y2);
    ecl = sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
    cout << fixed << setprecision(7) << ecl << " " << man << endl;
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