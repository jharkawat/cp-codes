#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define For(_i , N) for(int _i = 0 ;_i < N ; _i ++)
#define ForR(_i , N) for(int _i = N ;_i > 0 ; _i --)
#define ForI(_i , a , N) for(int _i = a ;_i < N ; _i ++)
#define ForIR(_i , a , N) for(int _i = N ;_i > a ; _i --)
#define INF (2139062143)

int main()
{
    int t;
    cin >> t;
    For(i,t)
    {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        int max1 = 0;
        int max2 = 0;
        int x;
        For(j,k1)
        {
            cin >> x;
            if(x>max1)
            {
                max1 = x;
            }
        }
        For(j,k2)
        {
            cin >> x;
            if(x>max2)
            {
                max2 = x;
            }
        }
        if(max1>max2)
        cout << "YES" << endl;
        else
        cout << "NO" << endl;

    }

}