#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve(){
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 0; i < (p+1)*n+1; ++i) {
        for (int j = 0; j < (p+1)*m + 1; ++j) {
            if(i%(p+1) == 0 || j%(p+1) == 0) cout<<"*";
            else if((i+j)%((p+1)*2)==0) cout<<"/";
            else if((i-j)%((p+1)*2)==0) cout<<"\\";
            else cout<<".";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
// O(m*n)
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