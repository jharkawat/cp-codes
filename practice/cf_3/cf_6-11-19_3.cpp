#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k
    cin >> k;
    for(int i = 0 ; i < k; i++)
    {
        int n;
        string s,t;
        cin >> s;
        cin >> t;
        arrs[26];
        arrt[26];
        for(int j= 0; j<n ; j++)
        {
            arrs[j] = 0;
            arrt[j] = 0;
        }
        for(int j = 0 ; j<n ; j++)
        {
            arrs[s.at(j)-a]++;
            arrt[s.at(j)-a]++; 
        }
    }
}