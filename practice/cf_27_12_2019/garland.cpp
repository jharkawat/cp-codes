#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define For(_i , N) for(int _i = 0 ;_i < N ; _i ++)
#define ForR(_i , N) for(int _i = N ;_i > 0 ; _i --)
#define ForI(_i , a , N) for(int _i = a ;_i < N ; _i ++)
#define ForIR(_i , a , N) for(int _i = N ;_i > a ; _i --)
#define INF (2139062143)

int main()
{
    int t;
    cin >> t;
    For(i,t)
    {
        ll arr[3];
        cin >> arr[0]; 
        cin >> arr[1];
        cin >> arr[2];
        sort(arr, arr+3);
        if(arr[2] <= (arr[0] + arr[1] + 1 ))
        cout << "YES" << endl;
        else 
        cout << "NO" << endl;
    }

    return 0;
}