#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0 ; i<t ;i++ )
    {
        string s;
        cin >> s;
        char x, y;
        int a = s.size();
        char str[a+1];
        strcpy(str, s.c_str());
        for(int j = 0 ; j < a ; j++ )
        {
            if( (str[j] == str[j+1]) && str[j] != '?' )
            {
                cout << -1 << endl;
                cout << "in here" << endl;
            }
            else if(str[j] == '?') 
            {
                if(j=0)
                {
                    if(str[j+1] == 'a')
                    {
                        str[j] = "b";
                    }
                    else if(str[j+1] == 'b')
                    {
                        str[j] = "c";
                    }
                    else if(str[j+1] == 'c')
                    {
                        str[j] = "a";
                    }
                }
                else if(j=(a-1))
                {
                    if(str[j-1] == 'a')
                    {
                        str[j] = "b";
                    }
                    else if(str[j-1] == 'b')
                    {
                        str[j] = "c";
                    }
                    else if(str[j-1] == 'c')
                    {
                        str[j] = "a";
                    }
                }
            else
            {
                x = str[j-1];
                y = str[j+1];
                if(y != '?')
                {
                    if(x=='a' && y=='a')
                    {
                        str[j] = "b";
                    }
                    else if(x=='b' && y=='b')
                    {
                        str[j] = "c";
                    }
                    else if(x=='c' && y=='c')
                    {
                        str[j] = "a";
                    }
                    else if(x=='a' && y=='b')
                    {
                        str[j] = "c";
                    }
                    else if(x=='a' && y=='c')
                    {
                        str[j] = "b";
                    }
                    else if(x=='b' && y=='a')
                    {
                        str[j] = "c";
                    }
                    else if(x=='b' && y=='c')
                    {
                        str[j] = "a";
                    }
                    else if(x=='c' && y=='a')
                    {
                        str[j] = "b";
                    }
                    else if(x=='c' && y=='b')
                    {
                        str[j] = "a";
                    }
                }
                else 
                {
                    if(x == 'a')
                    {
                        str[j] = "b";
                    }
                    else if(x == 'b')
                    {
                        str[j] = "c";
                    }
                    else if(x == 'c')
                    {
                        str[j] = "a";
                    }
                }

            }
                
            }
        }
        for (int i = 0; i < a; i++) 
        cout << str[i]; 
        cout << endl;
    }
}