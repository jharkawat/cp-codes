#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test() int t;cin>>t;while(t--)
#define ll long long
#define For(_i , N) for(int _i = 0 ;_i < N ; _i ++)
#define ForR(_i , N) for(int _i = N ;_i > 0 ; _i --)
#define ForI(_i , a , N) for(int _i = a ;_i < N ; _i ++)
#define ForIR(_i , a , N) for(int _i = N ;_i > a ; _i --)
#define INF (2139062143)

int gcd(int a, int b) 
{ 
    // Everything divides 0  
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
   
    // base case 
    if (a == b) 
        return a; 
   
    // a is greater 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
} 
 

int main()
{
	test()
	{
        ll n;
        cin >> n;
        ll arr[n], ans[n];
        For(i,n)
        {
            cin >> arr[i];
        }
        int m = sizeof(arr)/sizeof(arr[0]);
        sort(arr, arr+m);
        int i = 0;
        int j = n-1;
        for(int k = 0; k<n; k = k+2)
        {
            ans[k] = arr[i];
            ans[k+1] = arr[j];
            i++;
            j--;
        }
        For(i,n)
        {
            cout << arr[i] << " " ;

        }
        cout << endl;

        For(i,n)
        {
            cout << ans[i] << " " ;

        }
        cout << endl;


	}

}