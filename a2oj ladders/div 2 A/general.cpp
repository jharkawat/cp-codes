#include<bits/stdc++.h>

using namespace std;

#define FOR(_i , N) for(int _i = 0 ;_i < N ; _i ++)
#define FORe(_i , N) for(int _i = N ;_i > 0 ; _i --)
#define ll long long
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int min = 101;
    int max = 0;
    int pos_min, pos_max, ans;
    FOR(i,n)
    {
        cin >> arr[i];
    }
    FOR(i, n)
    {
        if(arr[i] <= min)
        {
            min = arr[i];
            pos_min = i;
        }
        if(arr[i] > max)
        {
            max = arr[i];
            pos_max = i;
        }

    }
    if(pos_min > pos_max)
    {
        //cout << pos_min << pos_max << endl;
       ans = (n-pos_min-1) + (pos_max) ; 
       cout << ans << endl;
    }
    else
    {
        //cout << pos_min << pos_max << endl;
        ans = ((n-pos_min-1) + (pos_max) - 1);
        cout << ans << endl;
    }

    
}