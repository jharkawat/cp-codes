#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int x, y, z;
    for(int i = 0; i<t ; i++)
    {
        int n, a, b, c;
        int N, M;
        int count1 = 0, count2 = 0, count3 = 0;
        cin >> n;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        string o[n];
        for(int j = 0; j < n ; j++)
        {
            if(s.at(i) == 'R')
            {
                count1++;
            }
            else if(s.at(i) == 'P')
            {
                count2++;
            }
            else if(s.at(i) == 'S')
            {
                count3++;
            }
        }

        x = (b-count1);
        y = (c-count2);
        z = (a-count3);

        N = abs(x)+abs(y)+abs(z);
        M = (n+1)/2;
        if(N > M)
        {
            cout << "yes" << endl;
            for(int k = 0 ; k <n ; k++)
            {
                if((s.at(i) == 'R') && (b > 0))
                {
                    o[i] = 'P';
                    b--;
                }
                else if((s.at(i) == 'P') && (c > 0))
                {
                    o[i] = 'S';
                    c--;
                }
                else if((s.at(i) == 'S') && (a > 0))
                {
                    o[i] = 'R';
                    a--;
                }
                else if((s.at(i) == 'R') && (b <= 0) && (y > 0) )
                {
                    o[i] = 'S';
                    y--;
                    c--;
                }
                else if((s.at(i) == 'R') && (b <= 0) && (y <= 0) && (z >0) )
                {
                    o[i] = 'R';
                    z--;
                    a--;
                }
                else if((s.at(i) == 'P') && (c <= 0) && (z > 0) )
                {
                    o[i] = 'R';
                    z--;
                    a--;
                }
                else if((s.at(i) == 'P') && (c <= 0) && (z <= 0) && (x >0) )
                {
                    o[i] = 'P';
                    x--;
                    b--;
                }
                else if((s.at(i) == 'S') && (a <= 0) && (x > 0) )
                {
                    o[i] = 'R';
                    x--;
                    b--;
                }
                else if((s.at(i) == 'S') && (a <= 0) && (x <= 0) && (y >0) )
                {
                    o[i] = 'S';
                    y--;
                    c--;
                }  
            }
            cout << o << endl;


        }
        else 
        {
            cout << "no" << endl;
        }


    }
}
