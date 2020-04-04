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

int main()
{
	test()
	{
        int n, x;
        cin >> n >> x;
        unordered_set<int> vec;
        For(i,n)
        {
            int p;
            cin >> p;
            vec.insert(p);
        }
        int j =1;
        while(x != 0)
        {
            if(vec.find(j) != vec.end())
            {
                j++;
            }
            else 
            {
                x--;
                j++;
            }    
        }
        if(vec.find(j) == vec.end())
        {
            j--;
        }
        
        cout << j << endl;

	}

}