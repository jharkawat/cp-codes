#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)
{
    while (a != b) { 
        if (a > b)         
            a = a - b;         
        else        
            b = b - a;         
    } 
    return a; 
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0 ; i < t ; i++)
    {
        long long a ,b;
        cin >> a >> b;
        if(gcd(a,b) == 1)
        {
            cout << "Finite" << endl;
        }
        else 
        {
            cout << "Infinite" << endl; 
        }
    }
}