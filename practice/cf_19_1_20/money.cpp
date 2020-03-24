#include<bits/stdc++.h>

using namespace std;

#define FOR(_i , N) for(int _i = 0 ;_i < N ; _i ++)

int main()
{
    double n;
    cin>> n;
    double ans = 0.000000000;
    for(double i = 0; i<(n); i++)
    {
        ans = ans + 1.0000000/(n-i);
    }
    cout << ans <<endl;
}