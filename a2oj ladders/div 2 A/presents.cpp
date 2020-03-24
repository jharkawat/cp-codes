#include<bits/stdc++.h>

using namespace std;

#define ll long long 
#define FOR(_i, a, N) for(int _i = a; _i <N; _i ++)
#define FORE(_i, a, N) for(int _i = a; _i > N; _i --)

int main()
{
    int n, k;
    k =0;
    cin >> n;
    // string s;
    // cin >> s;
    int arr[n], ans[n];
    // for(int i =0 ; i <= (n-1)*2 ; i++)
    // {
    //     if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
    //     {
    //         arr[k] = s[i] - 48;

    //         k++;
    //     }
    // }
    // cout << k << endl;
    FOR(i,0,n)
    {
        cin >> arr[i];
    }
  
    FOR(i,0,n)
    {
        int y;
        y = arr[i]-1;
        ans[y] = i+1;
    }
    FOR(i,0,n)
    {
        cout<< ans[i] << " " ;
    }
    cout << endl;
}