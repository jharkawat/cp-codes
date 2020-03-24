#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    for(int i=0; i<k; i++)
    {
        int n;
        cin >> n;
        string s, t;
        cin >> s;
        cin >> t;
        string S,T;
        int count = 0;
        for(int x = 0; x<n; x++)
        {
            if(s.at(x) != t.at(x))
            {
                S = S + s.at(x);
                T = T + t.at(x);
                count++;
            }
        }
        
        if( (count == 2) && (S.at(0) == S.at(1)) && (T.at(0) == T.at(1)) )
        {
            cout << "YES" << endl;
        }
        else
        {
            cout<< "NO" << endl;
        }
    }    
}