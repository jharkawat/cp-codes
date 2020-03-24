#include<bits/stdc++.h>

using namespace std;

#define FOR(_i , N) for(long long _i = 0 ;_i < N ; _i ++)


int main()
{
    int t;
    cin >> t;
    for(int i =0; i<t; i++)
    {
        long long n;
        cin >> n;
        int count = 0;
        long long arr[n];
        for(int j = 0 ; j<n; j++)
        {
            cin >> arr[j];
        }
        int m = sizeof(arr) / sizeof(arr[0]); 
  
        //int countr = count_if(arr, arr + m, isOdd);
        int flag = 1;
        while(flag)
        {
            int x, max;
            max = 0;
            count++;
            for(int k = 0; k<n; k++)
            {
                if((arr[k]%2) == 0 )
                {   
                    if(arr[k] > max)
                    {
                        max = arr[k];
                        
                    }
                    
                }
            }

            if(max == 0)
            {
                flag = 0;
                break;
            }

            for(int o = 0; o<n; o++)
            {
                if(arr[o] == max)
                {
                    arr[o] = (arr[o]/2) ;
                }
            }
            
             
            
        }
        cout << count-1<< endl;

    }
}