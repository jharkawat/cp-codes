#include<bits/stdc++.h>

using namespace std;

#define FOR(_i , N) for(int _i = 0 ;_i < N ; _i ++)

int main()
{
    int q;
    cin >> q;
    FOR(i,q)
    {
        long long int a, b, c, x, y, z, min, cal;
        min = 0;
        cin >> a >> b >> c;

        x = a; y = b; z = c;
        min = abs(x-y) +  abs(x-z) + abs(y-z);

        x = a+1; y = b; z = c;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        x = a-1; y = b; z = c;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        x = a; y = b+1; z = c;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        x = a; y = b-1; z = c;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        x = a; y = b; z = c+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        x = a; y = b; z = c-1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;





        x = a+1; y = b+1; z = c;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;
        
        x = a+1; y = b-1; z = c;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        x = a+1; y = b; z = c+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        x = a+1; y = b; z = c-1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        x = a+1; y = b+1; z = c+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;
        
        x = a+1; y = b-1; z = c+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        x = a+1; y = b-1; z = c+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        x = a+1; y = b+1; z = c-1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;



        x = a-1; y = b+1; z = c;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;
        
        x = a-1; y = b-1; z = c;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        x = a-1; y = b; z = c+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        x = a-1; y = b; z = c-1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        x = a-1; y = b+1; z = c+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;
        
        x = a-1; y = b-1; z = c+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        x = a-1; y = b-1; z = c+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        x = a-1; y = b+1; z = c-1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;












        y = b+1; x = a+1; z = c;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;
        
        y = b+1; x = a-1; z = c;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        y = b+1; x = a; z = c+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        y = b+1; x = a; z = c-1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        y = b+1; x = a+1; z = c+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;
        
        y = b+1; x = a-1; z = c+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        y = b+1; x = a-1; z = c+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        y = b+1; x = a+1; z = c-1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;



        y = b-1; x = a+1; z = c;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;
        
        y = b-1; x = a-1; z = c;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        y = b-1; x = a; z = c+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        y = b-1; x = a; z = c-1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        y = b-1; x = a+1; z = c+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;
        
        y = b-1; x = a-1; z = c+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        y = b-1; x = a-1; z = c+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        y = b-1; x = a+1; z = c-1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

















        z = c+1; y = b+1; x = a;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;
        
        z = c+1; y = b-1; x = a;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        z = c+1; y = b; x = a+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        z = c+1; y = b; x = a-1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        z = c+1; y = b+1; x = a+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;
        
        z = c+1; y = b-1; x = a+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        z = c+1; y = b-1; x = a+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        z = c+1; y = b+1; x = a-1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;



        z = c-1; y = b+1; x = a;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;
        
        z = c-1; y = b-1; x = a;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        z = c-1; y = b; x = a+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        z = c-1; y = b; x = a-1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        
        if(cal < min)min = cal;

        z = c-1; y = b+1; x = a+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;
        
        z = c-1; y = b-1; x = a+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        z = c-1; y = b-1; x = a+1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;

        z = c-1; y = b+1; x = a-1;
        cal = abs(x-y) +  abs(x-z) + abs(y-z);
        if(cal < min)min = cal;
        

        cout << min << endl;



    }
}