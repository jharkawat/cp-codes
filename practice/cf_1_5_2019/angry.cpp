#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define For(_i , N) for(int _i = 0 ;_i < N ; _i ++)
#define ForR(_i , N) for(int _i = N ;_i > 0 ; _i --)
#define ForI(_i , a , N) for(int _i = a ;_i < N ; _i ++)
#define ForIR(_i , a , N) for(int _i = N ;_i > a ; _i --)
#define INF (2139062143)

int main()
{
    int t;
    cin >> t;
    For(i,t)
    {
        int k;
        cin >> k;
        string str;
        cin >> str;
        int check;
        int first = 0;
        int max = 0;
        int m = str.size();
        //cout<< m << endl;
        For(j,m)
        {
            if(str[j] == 'A')
            {
                //cout << "in here" << j <<endl;
                int first = 0;
                ForI(k,j+1,m)
                {
                    if(str[k] == 'P')
                    {
                        first++;
                        //cout << first << endl;
                    }
                    else
                    {
                        break;
                    }
                }
                if(first > max)
                {
                    max = first;
                }
            }
        }
        cout << max << endl;
    }
}