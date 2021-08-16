#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    int a,b,c,d;
    a = min(x2,x4);
    b = max(x1,x3);
    c = min(y2,y4);
    d = max(y1,y3);


    int total = abs(x2-x1)*abs(y2-y1) + abs(x4-x3)*abs(y4-y3);
    int intersection = 0;

    if(a>b && c>d)
    {
        intersection = (a-b)*(c-d);
    }
    cout << intersection << " " << total-intersection << "\n";

}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    
    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}