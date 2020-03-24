#include<bits/stdc++.h>

using namespace std;

#define FOR(_i , N) for(int _i = 0 ;_i < N ; _i ++)

int* check(int arr[], int n, string s)
{
    FOR(i,26)
    {
        arr[i] = 0;
    }
    FOR(j,n)
    {
        if(s[j] == 'a')
        arr[0]++;
        else if(s[j] == 'b')
        arr[1]++;
        else if(s[j] == 'c')
        arr[2]++;
        else if(s[j] == 'd')
        arr[3]++;
        else if(s[j] == 'e')
        arr[4]++;
        else if(s[j] == 'f')
        arr[5]++;
        else if(s[j] == 'g')
        arr[6]++;
        else if(s[j] == 'h')
        arr[7]++;
        else if(s[j] == 'i')
        arr[8]++;
        else if(s[j] == 'j')
        arr[9]++;
        else if(s[j] == 'k')
        arr[10]++;
        else if(s[j] == 'l')
        arr[11]++;
        else if(s[j] == 'm')
        arr[12]++;
        else if(s[j] == 'n')
        arr[13]++;
        else if(s[j] == 'o')
        arr[14]++;
        else if(s[j] == 'p')
        arr[15]++;
        else if(s[j] == 'q')
        arr[16]++;
        else if(s[j] == 'r')
        arr[17]++;
        else if(s[j] == 's')
        arr[18]++;
        else if(s[j] == 't')
        arr[19]++;
        else if(s[j] == 'u')
        arr[20]++;
        else if(s[j] == 'v')
        arr[21]++;
        else if(s[j] == 'w')
        arr[22]++;
        else if(s[j] == 'x')
        arr[23]++;
        else if(s[j] == 'y')
        arr[24]++;
        else if(s[j] == 'z')
        arr[25]++;
    }
    return arr;
    
}

int main()
{
    int q;
    cin >> q;
    FOR(k,q)
    {
        string pas, has;
        cin >> pas;
        cin >> has;
        int n,m,diff,count;
        int arr[26];
        int flag = 1;
        int stag = 1;
        n = pas.size();
        m = has.size();
        diff = m-n;
        int *sol = check(arr,n,pas);

        for(int l = 0; l<=diff; l++)
        {
            if(stag)
            {
                string pass;
                pass = has.substr(l,n);
                int arrcheck[26];
                count = 0;
                int *mid = check(arrcheck,n,pass);
                FOR(a,26)
                {
                    if(mid[a] == sol[a])
                    {
                        count++;
                        if(count == 26)
                        {
                            cout << "YES" << endl;
                            flag = 0;
                            stag = 0;
                            break;
                        }                    
                    }
                    else
                    {
                        break;

                    }
                }
            }
        }
        if(flag)
        {
            cout << "NO" << endl;
        }
    }
}