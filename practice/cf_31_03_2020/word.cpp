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
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll count = 0;
        ll nos = n/k;
        ll arr[nos];
        For(i,nos)
        {
            arr[i] = 0;
        }
        For(i,nos)
        {
            For(j,k/2)
            {
                if(s[i*k+j] == s[(i+1)*k-(j+1)])
                {
                    arr[i]++;
                }
            }
        }
        ll index = max_element(arr, arr + nos) - arr;
        for(i = k*index;i<k*(index+1);i++)
        {
            ll col;
            for(j=0; j<nos; j++)
            {
                string temp, temp1;
                temp[j] = s[j*k];
                temp1[j] = s[(j+1)*k];
            }
            ll ch1[26], ch2[26];
            for(k = 0; k<nos; k++)
            {
                ch1[temp[k]-97]++;
                ch2[temp1[k]-97]++;
            }
            ll max1 = max_element(ch1, ch1 + 26) - ch1;
            ll max2 = max_element(ch2, ch2 + 26) - ch2;
            if(max1 >= 2 )

        }


	}

}