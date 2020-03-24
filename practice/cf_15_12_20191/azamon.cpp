#include<bits/stdc++.h>

using namespace std;

#define ll long long 
#define FOR(_i, a, N) for(ll _i = a; _i <N; _i ++)
#define FORE(_i, a, N) for(ll _i = a; _i > N; _i --)

int main()
{
    int t;
    cin >> t;
    FOR(i, 0, t)
    {
        string s, c;
        cin >> s >> c;
        int count1 = 0;
        int count2 = 0;
        int flag = 1;
        int m = s.size();
        int o = c.size();
        int mins = min(m,o);
        FOR(j, 0, m)
        {
            if((flag == 1) && c[j] != '\0')
            {
                if( s[j] > c[j])
                {
                    int x = c[j];
                    FOR(k,j+1,m)
                    {
                        if( s[k] < x)
                        {
                            char z;
                            char y = s[k];
                            z = s[j];
                            s[j] = y;
                            s[k] = z;
                            cout << s << endl;
                            flag = 0;
                            break;

                        }
                    }
                }
                else if( s[j] < c[j])
                {
                    cout << s << endl; 
                    flag = 0;  
                } 
                else if(s[j] == c[j])
                {
                    count1++;
                }

                if(flag == 0)
                {
                    break;
                } 
            }
        }
        for(int v = 0; v < m ; v++ )
        {
            if((flag == 1) && (count1 == mins) && (mins != m));
        }
        if((flag == 1) && (count1 != mins))
        {
            //cout << count1 << min << endl; 
            cout << "---" << endl;
        }
        else if((flag == 1) && (count1 == mins) && (mins == m))
        {
            cout << s << endl;
        }


    } 
}