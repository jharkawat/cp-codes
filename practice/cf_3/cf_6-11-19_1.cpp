#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    for(int i = 0; i<k; i++)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int j =0; j<n ; j++)
        {
            cin >> arr[j];
        }
        int x = sizeof(arr)/sizeof(arr[0]);
        sort(arr, arr+x, greater<int>());

        int count;
        count = 0;

        for(int j=0; j<n; j++)
        {
            if(arr[j] >= (j+1))
            {
                count++;
            }
            else if(arr[j] <= (j+1))
            {
                break;
            }
        }
        cout << count << endl;
    }
}