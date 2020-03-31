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
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        ll x ,y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2; 
        ll hori, vert;
        hori = abs(a-b);
        vert = abs(c-d);
        ll moveh, movev;
        moveh = abs(x2-x1);
        movev = abs(y2-y1);
        if(((x1 == x2 ) && ((a!=0) || (b!=0))) || ((y1 == y2 ) && ((c!=0) || (d!=0))))
        {
            cout << "NO" << endl;
        }
        else 
        {
            if((hori <= moveh) && (vert <= movev))
            {
                if(((x1<=x) && (x<=x2)) && ((y1<=y) && (y<=y2)))
                {
                    if(((x-x1) >= (a-b)) && ((x2-x) >= (b-a)) && ((y-y1) >= (c-d)) && ((y2-y) >= (d-c)))
                    {
                        cout << "YES" << endl;
                    }
                    else 
                    {
                        cout << "NO" << endl;
                    }

                }
                else
                {
                    cout << "NO" << endl;
                }

            }
            else 
            {
                cout << "NO" << endl;
            }
        }

	}

}