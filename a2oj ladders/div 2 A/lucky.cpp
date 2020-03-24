#include<bits/stdc++.h>

using namespace std;

#define ll long long 
#define FOR(_i, a, N) for(int _i = a; _i <=N; _i ++)
#define FORE(_i, a, N) for(int _i = a; _i > N; _i --)

bool islucky(int i)
{
    if(i%4 == 0 || i%7 == 0 || i%47 == 0 || i%44 == 0 || i%77 == 0 || i%444 == 0 || i%447 == 0 || i%474 == 0 || i%744 == 0 || i%477 == 0 || i%747 == 0 || i%774 == 0 || i%777== 0 || i%74 == 0 )
    return true;
    else 
    return false;
}
int main()
{
    int i;
    cin >> i;
    FOR(j,1,i)
    {
        if(islucky(j))
        {
            if(i%j == 0)
            {
                cout << "YES" << endl;
                return 0;
            } 
        }
    }
    cout << "NO" << endl;
    return 0;
}