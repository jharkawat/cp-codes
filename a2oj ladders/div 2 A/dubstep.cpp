#include<bits/stdc++.h>

using namespace std;

#define FOR(_i , N) for(int _i = 0 ;_i < N ; _i ++)
#define FORe(_i , N) for(int _i = N ;_i > 0 ; _i --)
#define ll long long

int main()
{
    string mix;
    cin >> mix;
    int k =0;
    int flag = 0;
    int stag = 0;
    int m = mix.size();
    char ori[200];
    FOR(i,m)
    {
        if((mix[i] == 'W') && (mix[i+1] == 'U') && (mix[i+2] == 'B') && flag == 0)
        {
            i = i+2;
        }
        else if((mix[i] == 'W') && (mix[i+1] == 'U') && (mix[i+2] == 'B') && flag == 1)
        {
            i = i+2;
            if(stag == 0)
            {
                ori[k] = ' ';
                k = k+1;
            }
            stag = 1;
            
        }
        else 
        {
            // cout << "in here" << endl;
            // cout << mix[i] << endl;
            ori[k] = mix[i];
            // cout << ori[k] << "ye" << endl;
            stag = 0;
            k++;
            flag = 1;
        }
    }
    //cout << ori << endl;
    // cout << mix << endl;
    for(int j=0; j<k; j++)
    {
        cout << ori[j] ;
    }
    cout << endl;
}