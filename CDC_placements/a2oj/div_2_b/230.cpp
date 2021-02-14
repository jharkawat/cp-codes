#include<bits/stdc++.h>

using namespace std;

int main()
{
    int arr[1000005];
    arr[0]=0;
    arr[1]=0;
    arr[2]=1;
    arr[3]=1;
    for(long long int k=4; k<1000005; k++)
    {
        int count=0;
        for(long long int i=2; i<=sqrt(k); i++)
        {
            if(k%i == 0)
            {
                count++;
                arr[k+1]=0;
                break;
            }
        }
        if(count==1)
        {
            arr[k+1]=1;
        }
        
    }
    long long int t;
    cin >> t;
    for(long long int j=0; j<t;j++)
    {
        long long int n; 
        cin >> n;
        long long int p = sqrt(n);
        if((n<4) || (p*p != n))
        {
            cout << "NO" << endl;
        }
        else
        {
            if(arr[p]==1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}