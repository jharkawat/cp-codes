#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int value, check;
    value = 0;
    for(int i = 0; i<t; i++)
    {
        int N;
        cin >> N;
        int a[N-1];
        a[0] = 0;
        a[1] = 0;
        for(int j = 2; j<N ; j++)
        {
            check = a[j-1];
            for(int k = 0 ; k < (j-1) ; k++)
            {
                if( (a[j-k-2] == check) && ((j-k-2) > -1) ) 
                {
                    a[j] = k+1;
                    break;
                }
                else if((j-k-2) > -1)
                {
                    a[j] = 0;
                }

            }
        }
        for(int i = 0; i<N; i++)
        {
            cout << a[i] << " " ;
        }    
        int occur, count;
        count = 1;
        occur = a[N-1];
        for(int i = 0; i<(N-1); i++)
        {
            if(a[i] == occur)
            count++;
        }
        cout << "\n" << count << endl;
    }
}