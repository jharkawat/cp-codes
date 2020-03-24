#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    cin >> a;
    cin >> b;
    int i;
    int x = a.size();
    //cout << 1/2 << endl;
    for(int j= 0 ; j<x ; j++)
    {
        a[j] = tolower(a[j]);
        b[j] = tolower(b[j]);
    }
    for(i = 0; i<x ; i++)
    {
        if(a[i] > b[i])
        {
            cout << "1" << endl;
            return 0;
        }
        else if(a[i] < b[i])
        {
            cout << "-1" << endl;
            return 0;
        }
    }
    if(i == x)
    {
        cout << "0" << endl;
    }
    return 0;
}