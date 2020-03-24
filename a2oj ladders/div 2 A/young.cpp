#include<bits/stdc++.h>

using namespace std;

#define FOR(_i , N) for(int _i = 0 ;_i < N ; _i ++)
#define FORe(_i , N) for(int _i = N ;_i > 0 ; _i --)
#define ll long long

int main()
{
    int n;
    cin >> n;
    int x[n] , y[n], z[n];
    FOR(i,n)
    {
        cin >> x[i];
        cin >> y[i];
        cin >> z[i];
    }
    int sumx = 0;
    int sumy = 0;
    int sumz = 0;
    FOR(j,n)
    {
        sumx = sumx + x[j];
        sumy = sumy + y[j];
        sumz = sumz + z[j];
    }


    if( (sumx == 0) && (sumy == 0) && (sumz == 0))
    cout << "YES" << endl;
    else 
    cout << "NO" << endl;
    return 0;

}