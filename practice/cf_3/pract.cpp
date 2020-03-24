#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i<t ; i++)
    {
        int n,k;
        cin >> n;
        int arr1[n], arr2[n];
        for(int j = 0; j<n; j++)
        {
            cin >> arr1[j];
        }
        for(int j = 0; j<n; j++)
        {
            cin >> arr2[j];
        }
        int r,l,diff,count;
        r = 0;
        for(k = 0; k<n; k++)
        {
            if(arr1[k] != arr2[k])
            {
                r = k;
                diff = (arr2[k]-arr1[k]);
                break;
            }
        }
        
        count = 0;
        l = 0;
        for(k=(r+1) ; k<n ; k++)
        {
            //cout << "in here" << endl;
            //cout << k << endl;    
            if((arr1[k] != arr2[k]) && (diff == (arr2[k]-arr1[k])))
            {
                count++;
                
                l= k;
            }    
        }
        //cout << l << endl;
        //cout << r << endl;
        //cout << count << endl;
        if( l == (r + count) && (diff > 0))
        {
            cout << "YES" << endl;
        } 
        else 
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}