#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    for(int i = 0 ; i < k; i++)
    {
        int arr[3];
        cin >> arr[0] >> arr[1] >> arr[2];
        int n = sizeof(arr)/sizeof(arr[0]);    

        sort(arr, arr+n);
        int count;
        count = 0;
        while(arr[1] >0)
        {
            if(arr[0] > 0)
            {
                arr[0] --;
                arr[2] --;
                count ++;
                sort(arr, arr+n);
            }
            else if(arr[0] == 0 && arr[1] > 0) 
            {   
                arr[2] --;
                arr[1] --;
                count ++;
                sort(arr, arr+n);
            }               
        }
        cout << count << endl;
         
    }
}