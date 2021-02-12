#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int t;
    cin >> t;
    for(long long int j=0; j<t;j++)
    {
        long long int n; 
        int count=0;
        cin >> n;
        long long int p = sqrt(n);
        if((n<4) || (p*p != n))
        {
            cout << "NO" << endl;
            continue;
        }
        for(long long int i=2; i<p; i++)
        {
            if(n%i == 0)
            {
                count++;
                cout << "NO" << endl;
                break;
            }
        }
        if(count ==0)
        {
            cout << "YES" << endl;
        }
    }
}