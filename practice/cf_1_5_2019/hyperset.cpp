#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define For(_i , N) for(int _i = 0 ;_i < N ; _i ++)
#define ForR(_i , N) for(int _i = N ;_i > 0 ; _i --)
#define ForI(_i , a , N) for(int _i = a ;_i < N ; _i ++)
#define ForIR(_i , a , N) for(int _i = N ;_i > a ; _i --)
#define INF (2139062143)

void sort(char** names, int n) 
{ 
    int i, j; 
  
    // Perform sort operation using bubble sort 
    for (i = 0; i < n - 1; i++) 
        for (j = 0; j < n - i - 1; j++) 
            if (strcmp(names[j], names[j + 1]) > 0) { 
                char* temp; 
                temp = (char*)calloc(30, sizeof(char)); 
                strcpy(temp, names[j]); 
                strcpy(names[j], names[j + 1]); 
                strcpy(names[j + 1], temp); 
            } 
} 

int main()
{
    int n,k;
    cin >> n >> k;
    char** str;
    str = (char**)calloc(n, sizeof(char*));
    int first, second, third;
    For(i,n)
    {
        str[i] = (char*)calloc(30, sizeof(char));
        cin >> str[i];
    }
    int count = 0;
    sort(str,n);
    // For(i,n)
    // {
    //     cout << str[i] << endl;
    // }    
    int e = 0;
    int s = 0;
    int t = 0;
    For(i,n)
    {
        if(str[i][0] == 'E')
        e++;
        else if(str[i][0] == 'S')
        s++;
        else if(str[i][0] == 'T')
        t++;
    }
    For(i,e-2)
    {
        if((str[i][k-1] == str[i+1][k-1]) && (str[i+2][k-1] == str[i+1][k-1]))
        count++;
    }
    ForI(i,(e-1),(e+s-2))
    {
        if((str[i][k-1] == str[i+1][k-1]) && (str[i+2][k-1] == str[i+1][k-1]))
        count++;
    }    
    ForI(i,(e+s-1),(e+s+t-2))
    {
        if((str[i][k-1] == str[i+1][k-1]) && (str[i+2][k-1] == str[i+1][k-1]))
        count++;
    }    

    For(i,(n-2))
    {
        //cout << str[i] << ' ';
        ForI(j,e,(n-1))
        {
            //cout << str[j] << ' ';
            ForI(l,e+s,n)
            {
                int stag = 0;
                //cout << str[l] << ' ';
                For(a,k)
                {
                    if( ((str[i][a] == str[j][a]) && (str[l][a] == str[j][a])) || ((str[i][a] != str[j][a]) && (str[l][a] != str[j][a])) && (str[l][a] != str[i][a]))
                    stag++;
                }
                if(stag == k)
                {
                    //cout <<"ans" << str[i] << ' ' << str[j] << ' ' << str[l] << ' ' << endl; 
                    count++;
                }
            }
        }

    }
    cout << count << endl;

}