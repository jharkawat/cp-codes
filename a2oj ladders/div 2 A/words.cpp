#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i;
    cin >> i;
    for(int j=0; j<i; j++)
    {
        string str, ans;
        cin >> str;
        int a = str.size();
        if(a <= 10)
        {
            cout << str << endl;
        }
        else
        {
            int b = a -2;
            cout << str.at(0) << b << str.at(a-1) << endl;
        }

    }
}
