#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve(){
    ll n,m;
    cin >> n >> m;
    for(int i=0; i<3*n+1; i++)
    {
        if(i%3 == 0)
        {
            for(int j=0; j<3*m+1; j++)
            {
                cout << "*";
            }
        }
        else
        {
            for(int j=0; j<3*m+1; j++)
            {
                if( j%3 == 0)
                {
                    cout << "*";
                }
                else
                {
                    cout << ".";
                }
            }
        }
        cout << endl;
    }

}
// O(m*n)

signed main(){
    IOS
    ll t;
    cin >> t;                                                                                                               
    while(t--)
    {
        solve();
    }
}