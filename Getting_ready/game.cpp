#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test() int t;cin>>t;while(t--)
#define ll long long
#define For(_i , N) for(int _i = 0 ;_i < N ; _i ++)
#define ForR(_i , N) for(int _i = N ;_i > 0 ; _i --)
#define ForI(_i , a , N) for(int _i = a ;_i < N ; _i ++)
#define ForIR(_i , a , N) for(int _i = N ;_i > a ; _i --)
#define INF (2139062143)

int gcd(int a, int b) 
{ 
    // Everything divides 0  
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
   
    // base case 
    if (a == b) 
        return a; 
   
    // a is greater 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
} 
 

int main()
{
	test()
	{
        long double n;
        cin >> n;
        ll a = n;
        cout << "a = " << a << endl; 
        long double m = n-a;
        cout << "m = " << m << endl;
        ll b = m*10000;
        cout << "b = " << b << endl;
        int c = gcd(10000,b);
        cout << "c = " << c << endl;
        cout << 10000/c << endl;
	}
}