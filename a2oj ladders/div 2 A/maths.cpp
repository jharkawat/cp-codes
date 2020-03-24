#include<bits/stdc++.h>

using namespace std;

#define FOR(_i , N) for(int _i = 0 ;_i < N ; _i ++ )
int main()
{
    int count1, count2, count3, k;
    count1 =0;
    count2 =0;
    count3 =0;
    string s;
    cin >> s;
    int n = s.size();
    FOR(i,n)
    {
        if(s[i] == '1')
        {
            count1++;
        }
        else if(s[i] == '2')
        {
            count2++;
        }
        else if(s[i] == '3')
        {
            count3++;
        }
    }
    for(k=0; count1 != 0; )
    {
        s[k] = '1';
        k = k+2;
        count1--;
        
    }
    for( ; count2 != 0; )
    {
        s[k] = '2';
        k = k+2;
        count2--;
    }
    for( ; count3 != 0; )
    {
        s[k] = '3';
        k = k+2;
        count3--;
    }
    cout<< s << endl;



}