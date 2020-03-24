#include<bits/stdc++.h>

using namespace std;

#define FOR(_i , N) for(int _i = 0 ;_i < N ; _i ++)
#define FOR_d(_i , N) for(int _i = N ;_i > 0 ; _i --)

int main()
{
    long int q;
    cin >> q; 
    FOR(i,q)
    {
        string s;
        cin >> s;
        long long int countd, countu, countl, countr;
        countd = 0;
        countu = 0;
        countl = 0;
        countr = 0;
        int n = s.size();
        FOR(j,n)
        {
            if(s[j] == 'D')
            countd++;
            else if(s[j] == 'U')
            countu++;
            else if(s[j] == 'L')
            countl++;
            else if(s[j] == 'R')
            countr++;

        }
        if(countr > countl)
        countr = countl;

        if(countr < countl)
        countl = countr;

        if(countu > countd)
        countu = countd;

        if(countu < countd)
        countd = countu;

        if((countd == 0) && (countl != 0) )
        countl = countr =1;

        if((countl == 0) && (countd != 0))
        countd = countu =1;
        
        int m = 2*countl + 2*countd;
        string ans;

        long long int k = 0;

        cout << m << endl;

        FOR_d(a,countr)
        {
            //ans[k] = (char)'R';
            //k++ ;
            cout << "R" ;
        }

        FOR_d(a,countu)
        {
            //ans[k] = (char)'U';
            //k++; 
            cout << "U";
        }
        FOR_d(a,countl)
        {
            //ans[k] = (char)'L';
            //k++;
            cout << "L"; 
        }
        FOR_d(a,countd)
        {
            //ans[k] = (char)'D';
            //k++;
            cout  << "D";
        }
        
        cout << endl;

//        cout << ans << endl;


    }
}