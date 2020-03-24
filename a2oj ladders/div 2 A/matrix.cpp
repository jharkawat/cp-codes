#include<bits/stdc++.h>

using namespace std;

#define ll long long 
#define FOR(_i, a, N) for(int _i = a; _i <N; _i ++)
#define FORE(_i, a, N) for(int _i = a; _i > N; _i --)

int main()
{
    int x,y,z;
    FOR(i,0,5)
    {
        FOR(j,0,5)
        {
            cin >> x;
            if(x == 1)
            {
                y = i;
                z = j;
            }
        }
    }
    cout << abs(y-2) + abs(z-2) << endl;
}