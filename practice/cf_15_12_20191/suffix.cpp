#include<bits/stdc++.h>

using namespace std;

#define ll long long 
#define FOR(_i, a, N) for(ll _i = a; _i <N; _i ++)
#define FORE(_i, a, N) for(ll _i = a; _i > N; _i --)

int main()
{
    int t;
    cin >> t;
    FOR(i,0,t)
    {
        string str;
        cin >> str;
        int m = str.size();
        if(str[m-1] == 'o')
        {
            cout << "FILIPINO" << endl;
        }
        else if(str[m-1] == 'u')
        {
            cout << "JAPANESE" << endl;
        }
        else if(str[m-1] == 'a')
        {
            cout << "KOREAN" << endl;
        }
    }
}