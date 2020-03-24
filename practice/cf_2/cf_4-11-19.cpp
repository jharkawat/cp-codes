#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    long long int t;
    cin >> t;
    for(int i = 0; i<t; i++)
    {
        long long int a, b, n, S;
        cin >> a >> b >> n >> S;
        if((S/n) >= a && ((S-n*a) > b))
        {
            cout << "NO" << endl;
        }
        else if((S/n) < a && ((S%n) > b))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }        
    }
}