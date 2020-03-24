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
        ll n, s;
        cin >> n >> s;
        ll arr[n];
        For(j,n)
        {
            cin >> arr[j];
        }
        ll sum = 0;
        int flag = 0;
        ll max = 0;
        ll pos = 0;
        For(j,n)
        {
            sum = sum + arr[j];
            if(arr[j] > max)
            {
                max = arr[j];
                pos = j+1;
            }
            if(sum == s)
            {
                if((max >= (arr[j+2] + arr[j+1])) && (j+2 < n))
                {
                    cout << pos << endl;
                    break;
                }    
            }
            else if( sum > s)
            {
                if(((sum- arr[pos-1] + arr[j] + arr[j+1] ) <= s) && (j+1 < n) && (pos != j+1))
                {
                    cout << pos << endl;
                    break;
                } 
                else if(((sum- arr[pos-1] + arr[j]) <= s) && (pos != j+1))
                {
                    cout << pos << endl;
                    break;
                }       
                else if(((sum- arr[pos-1] + arr[j+1]) <= s) && (pos == j+1) && (j+1<n))
                {
                    cout << pos << endl;
                    break;
                }                                    
                else 
                {
                    flag =1;
                    break;
                }    
            }

        }
        if(flag || (sum < s))
        {
            cout << '0' << endl;
        }

    }

}