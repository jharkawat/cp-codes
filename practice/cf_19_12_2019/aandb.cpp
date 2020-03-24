#include<bits/stdc++.h>

using namespace std;

#define FOR(_i , N) for(int _i = 0 ;_i < N ; _i ++)

int main()
{
    int t;
    cin >> t;
    FOR(i,t)
    {
        long long int a,b,diff;
        cin >> a;
        cin >> b;
        diff = abs(a-b);
        FOR(j, (diff/2))
        {
            int value;
            value = ((j*(j+1))/2);
            if(value == diff);
            {
                cout << j << endl;
                break;
            }
            if(value > diff)
            {
                int check;
                check = value-diff;
                if(check%2 == 0)
                {
                    cout << j << endl;
                    break;
                }
            }
        }
    }
}