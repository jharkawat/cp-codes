#include<bits/stdc++.h>

using namespace std;

#define FOR(_i, a, N) for(long long int _i = a; _i <N; _i ++)
#define FORE(_i, a, N) for(long long int _i = a; _i >= N; _i --)

int main()
{
    long long int a,b,c,d,e,f,profit;
    profit = 0 ;
    cin >> a >> b >> c >> d >> e >> f ;
    if(e>f)
    {
        long long int mins = min(a,d);
        profit = mins*e;
        if(d == mins)
        {
            cout << profit << endl;
            return 0;
        }
        else
        {
            d = d-mins;
            long long int intmins = min(b,c);
            long long int mins2 = min(intmins,d);
            profit = profit + mins2*f;
            cout << profit << endl;
            return 0;
        }

    }
    if (f >= e ) 
    {
        long long int intmins2 = min(b,c);
        long long int mins = min(intmins2,d);
        profit = mins*f;
        if(mins == d)
        {
            cout << profit << endl;
            return 0;
        }
        else
        {
            d = d-mins;
            long long int mins2 = min(a,d);
            profit = profit + mins2*e;
            cout << profit << endl;
            return 0;        
        }
    }
}    