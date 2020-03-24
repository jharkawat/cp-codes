#include<bits/stdc++.h>

using namespace std;

#define FOR(_i , N) for(int _i = 0 ;_i < N ; _i ++)
#define FORe(_i , N) for(int _i = N ;_i > 0 ; _i --)
#define ll long long
int main()
{
    int n,m;
    cin >> n >> m;
    int mins = min(m,n);
    if(mins%2 != 0)
    {
        cout << "Akshat" << endl;
    }
    else
    {
        cout << "Malvika" << endl;
    }
}