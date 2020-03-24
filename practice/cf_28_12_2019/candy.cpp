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
    For(i ,t)
    {
       int n, k;
       cin >> n >> k;
       if((n%k == 0) && (n>=k))
       {
           cout << n << endl;
       }
       else if((n%k != 0) && (n>=k))
       {
           if(n%k > (k/2))
           cout << (n-(n%k) + ((k)/2)) << endl;
           else 
           cout << n << endl;
       }
       else if((n<k))
       {
           if(n>(k/2))
           cout << (k/2) << endl;
           else
           cout << n << endl;
       }


    }
    

}