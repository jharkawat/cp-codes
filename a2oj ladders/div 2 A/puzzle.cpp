#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define FOR(_i , N) for(int _i = 0 ;_i < N ; _i ++)

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[m];
    FOR(i,m)
    {
        cin >> arr[i];
    }
    int o = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+o);
    ll min = 1000000000000;
    ll curr;
    FOR(i,(m-n+1))
    {
        curr = abs(arr[i] - arr[i+n-1]);
        if(curr < min)
        min = curr;
    }
    if(m!=n)
    cout << min << endl;
    else 
    cout << (arr[n-1] - arr[0]) << endl;
}