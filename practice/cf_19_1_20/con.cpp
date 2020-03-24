#include<bits/stdc++.h>

using namespace std;

#define FOR(_i , N) for(int _i = 0 ;_i < N ; _i ++)

// long long int binarySearch(long long int arr[],long long int l,long long int r,long long int x) 
// { 
//     if (r >= l) { 
//         int mid = l + (r - l) / 2; 
  
//         // If the element is present at the middle 
//         // itself 
//         if (arr[mid] == x) 
//             return 1; 
  
//         // If element is smaller than mid, then 
//         // it can only be present in left subarray 
//         if (arr[mid] > x) 
//             return binarySearch(arr, l, mid - 1, x); 
  
//         // Else the element can only be present 
//         // in right subarray 
//         return binarySearch(arr, mid + 1, r, x); 
//     } 
  
//     // We reach here when element is not 
//     // present in array 
//     return 0; 
// } 

long long int find(long long int arrn[], long long int s, long long int p, long long int n)
{
    long long int result1, result2;
    p++;
    if(s+p<n)
    {
        result1 = arrn[s+p];
    }    
    if(s-p>0)
    {
        result2 = arrn[s-p];
    }
    if(result1 && result2)
    {
        find(arrn,s,p,n);
    }
    else
    {
        return p;
    }        
}

int main()
{
    int t;
    cin >> t;
    FOR(i,t)
    {
        long long int n,s,k;
        long long int result , result1, result2;
        cin >> n >> s >>k;
        long long int arr[k];
        FOR(j,k)
        {
            cin >> arr[j];
        }
        long long int arrn[n] = {0};
        for(int j = 0 ; j<k; j++)
        {
            arrn[arr[j]] = 1;
        }
        int m = sizeof(arr)/sizeof(arr[0]);
        //sort(arr, arr+m);
        result = arrn[s];
        //cout << result << s << endl;
        long long int p = 0;
        long long int ans;
        if(result)
        {
            ans = find(arrn,s,p,n);
            p = ans;
            // result1 = 1;
            // result2 = 1;
            // while(result1 && result2)
            // {
            //     p++;
            //     if(s+p<n)
            //     {
            //         result1 = arrn[s+p];
            //     }    
            //     if(s-p>0)
            //     {
            //         result2 = arrn[s-p];
            //     }
            // }
        }
        cout << p << endl;
        // for(int j = 0; j<n ;j++)
        // {
        //     cout << arrn[j] << endl;
        // }
    }
}