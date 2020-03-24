#include<bits/stdc++.h>

using namespace std;

#define FOR(_i , N) for(int _i = 0 ;_i < N ; _i ++)

bool allCharactersSame(string s) 
{ 
    int n = s.length(); 
    for (int i = 0; i < n; i++) 
        if (s[i] != s[0]) 
            return false; 
  
    return true; 
} 

int main()
{
    int t;
    cin >> t;
    for(int j=0; j<t; j++)
    {
        long long int i;
        cin >> i;
        int count = 0;
        for(int k = 1; k<= i; k++)
        {
            string str;
            str = to_string(k);
            if(allCharactersSame(str))
            {
                count++;
            }

        }
        cout << count << endl;
    }

}