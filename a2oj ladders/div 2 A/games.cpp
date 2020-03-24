#include<bits/stdc++.h>

using namespace std;

#define FOR(_i , N) for(int _i = 0 ;_i < N ; _i ++)
#define FORe(_i , N) for(int _i = N ;_i > 0 ; _i --)
#define ll long long

int main()
{
    int n;
    cin >> n;
    int g[n], h[n];
    int count = 0;
    FOR(i,n)
    {
        cin >> g[i] >> h[i] ;
    }
    FOR(i,n)
    {
        FOR(j,n)
        {
            if(g[i] == h[j])
            count ++;

        }
    }
    cout << count << endl;
}