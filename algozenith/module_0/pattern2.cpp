#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve(){
    ll n,m,p;
    cin >> n >> m >> p;
    cout << endl;
    for(int i=0; i<((n*(p+1))+1); i++)
    {
        if(i%m == 0)
        {
            for(int j=0; j<((m*(p+1))+1); j++)
            {
                cout << "*";
            }
        }
        else
        {
            for(int j=0; j<((m*(p+1))+1); j++)
            {

                if(j%(2*m) == i%(2*m))
                {
                    cout << "\\" ;
                }   
                else if((i%(2*m)+j%(2*m)) == 2*m)
                {
                    cout << "/" ;
                }
                else if(j%m == 0)
                {
                    cout << "*" ;
                }
                else
                {
                    cout << "." ;
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