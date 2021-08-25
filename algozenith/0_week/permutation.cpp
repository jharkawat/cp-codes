#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t; cin >> t; 
    vector<int> vec;
    for(int i=1; i<=t; i++)
    {
        vec.push_back(i);
        cout << i << " ";
    }
    cout << "\n";
    while(next_permutation(vec.begin(),vec.end()))
    {
        for(int i=0; i<t; i++)
        {
            cout << vec[i] << " ";
        }
        cout << "\n";

    }
}