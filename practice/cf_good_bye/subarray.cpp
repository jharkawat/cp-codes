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
        ll n;
        cin >> n;
        ll arr[n];
        ll min = INF;
        ll max = 0;
        ll x;
        ll posmax, posmin;
        For(j,n)
        {
            cin >> x;
            arr[j] = x;
            if(x>max)
            {
                max = x;
                posmax = j;
            }
            if(x<min)
            {
                min = x;
                posmin = j;
            }
        }
        while( posmin != posmax )
        {
            if((posmax-posmin +1) <= (max-min) )
            {
                cout << "yes" << endl;
                ForI(j,posmin,(posmax+1))
                {
                    cout << arr[j] << ' ' ;
                }
                cout << endl;
                break;
            }
            else if((posmax-posmin +1) > (max-min))
            {
                ForI(j,posmin, posmax)
                {
                    if(arr[j]>max)
                    {
                        max = x;
                        posmax = j;
                    }
                    if(arr[j]<min)
                    {
                        min = x;
                        posmin = j;
                    }                    
                }
            }    
            
        }
        if(posmin == posmax)
        {
            cout << "NO" << endl;
        }
    }
    return 0;    
}