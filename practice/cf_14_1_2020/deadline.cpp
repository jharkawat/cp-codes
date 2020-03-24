#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define For(_i , N) for(int _i = 0 ;_i < N ; _i ++)
#define ForR(_i , N) for(int _i = N ;_i > 0 ; _i --)
#define ForI(_i , a , N) for(int _i = a ;_i < N ; _i ++)
#define ForIR(_i , a , N) for(int _i = N ;_i > a ; _i --)
#define INF (2139062143)


bool check()
{
    double n,d;
    cin >> n >> d;
    for(int j=0; j<n; j++)
    {
        if((j+ceil(d/(j+1))) <= n)
        {
            //cout << ceil(d/j+1) << endl;
            //cout << j + ceil(d/(j+1)) << endl;
            //cout << "in Here" << n << j <<  endl;
            //cout << "YES" << endl;
            return true;
        }
    }    
    return false;

}


int main()
{
    int t;
    cin >> t;
    ll count = 0;
    For(i,t)
    {
        if(check())
        cout << "YES" << endl;
        else
        cout << "NO" << endl;
    }

}