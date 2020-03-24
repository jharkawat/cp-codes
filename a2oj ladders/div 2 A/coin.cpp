#include<bits/stdc++.h>

using namespace std;

#define ll long long 
#define FOR(_i, a, N) for(ll _i = a; _i <N; _i ++)
#define FORE(_i, a, N) for(ll _i = a; _i >= N; _i --)

int sums(int arr[], int n)
{
    int sum = 0;
    FOR(i, 0, n)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    FOR(i,0,n)
    {
        cin >> arr[i]; 
    }
    int m = sizeof(arr)/sizeof(arr[0]);
    float sum = (float)(sums(arr, n))/2;
    //cout << sum << endl;
    sort(arr, arr+m);
    int count = 0;
    float add = 0;
    for(int j = n-1; j>-1; j--)
    {
        
        count++;
//        cout << "In here" << count << endl;
        add = add + arr[j];
        //cout << add << endl;
        //cout << add << "asdfa" << endl;
        if(add > sum)
        {
            //cout << "ab bol " << count << endl;
            break;

        }
        
    }
    cout << count << endl;
}