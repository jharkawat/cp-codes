#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ld n,k;
ld arr[10100], brr[10100];

void solve()
{
    cin >> n >> k;
    for(ld i = 0; i<n; i++)
    {
        cin >> arr[(ll)i];
    }
    for(ld i = 0; i<n; i++)
    {
        cin >> brr[(ll)i];
    }
    

}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    solve();

    // ll t; cin >> t; 
    // while(t--)
    // {
    //     solve();
    // }
}