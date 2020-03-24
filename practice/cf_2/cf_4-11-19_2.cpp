#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int n,m,d;
    cin >> n;
    cin >> m;
    cin >> d;
    int c[m];
    int a[n];
    int total,count1,count2;
    total =0;
    count1 = 1;
    count2 = 0;
    for(int i=0 ; i<m ; i++)
    {
        cin >> c[i];
    }
    for(int j=0; j<m ; j++)
    {
        total = total + c[j];
    }
    cout << total << endl; 
    if((n-total) > ((d-1)*(m+1)))
    {
        cout << "N0" << endl;
    }
    else
    {
        cout << "YES" << endl;
        for(int k =0 ; k<n ; k++)
        {
            if( (count2<(d-1)) && n>total )
            {
                a[k] = 0;
                count2++;
            }
            else if( (count2<(d-1)) && n==total )
            {
                a[k] = count1;
                count2=0;
                c[(count1-1)] = c[(count1-1)] - 1;
                total = total - c[(count1-1)];
                if( c[(count1-1)] == 0)
                {
                    count1++;
                }
            }
            else if( n > total )
            {
                a[k] = count1;
                count2 = 0;
                c[(count1-1)] = c[(count1-1)] - 1;
                total = total - c[(count1-1)];
                if( c[(count1-1)] == 0)
                {
                    count1++;                
                }    
            }
        }
        for(int i=0; i<n; i++)
        {
            cout << a[i] << endl;
        }
    }
}