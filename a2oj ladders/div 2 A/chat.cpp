#include<bits/stdc++.h>

//#define ll long long 
#define FOR(_i, a, N)  for(int _i = a ; _i <N ; _i ++)
#define FORE(_i, a, N) for(int _i = a; _i >= N; _i --)

using namespace std;

int main()
{
    string s;
    cin >> s;
    int flag = 0
    FOR(i,0,s.size())
    {
        if(flag == 0)
        {
            if(s[i] == 'h') 
            flag = 1; 
            continue;

        }
        if(flag == 1)
        {
            if(s[i] == 'e')
            flag = 2;
            continue;
        }
        if(flag == 2)
        {
            if(s[i] == 'l')
            flag = 3;
            continue;
        }
        if(flag == 3)
        {
            if(s[i] == 'l')
            flag = 4;
            continue;
        }
        if(flag == 4)
        {
            if(s[i] == 'o')
            flag = 5;
            continue;
        }
    }
    if(flag == 5)
    {
        //cout << flag << endl;
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

}