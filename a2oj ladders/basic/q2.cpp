#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i =0; i<t; i++)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        int ans[n];
        for(int i =0; i<n ;i++ )
        {
            cin >> arr[i] ;
            ans[i] = arr[i]/k;
        }
        int sum = 0;
        for(int i = 0; i <n ; i++)
        {
            sum += arr[i];

        }
        cout << sum << endl;
        
    }
    return 0;

}

