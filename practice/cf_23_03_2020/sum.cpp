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
    ll t;
    cin >> t;
    for(int i = 0; i<t; i++)
    {
        ll n, k;
        cin >> n >> k;
        if(((k%2 == 0) && (n%2 != 0)) || ((n%2 == 0) && (k%2 != 0)))
        {
            cout << "NO" << endl;
        }
        else
        {
            ll sum;
            sum = k^2;
            if(sum < n)
            {
                ll big = 2*k-1;
                ll diff = n-sum;
                if((diff%2 == 0) && (diff < big))
                {
                    cout << "YES" << endl;
                }
                else if (diff > big)
                {
                    cout << "YES" << endl;
                }
                else 
                {
                    cout << "NO" << endl;
                }
            }
            else if(sum == n)
            {
                cout << "YES" << endl;
            }
            else 
            {
                cout << "NO" << endl;
            }

        }

    }
    return 0;

}