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

int squares(int n)
{
    string s;
    s = to_string(n);
    int sum1 = 0;
    for(int j =0; j<s.size(); j++)
    {
        int i = s[j] - '0';
        sum1 += i*i;

    }
    return sum1;

}

int main()
{
    int n;
    cin >> n;
    unordered_set<int> arr;
    int m = squares(n);
    while( m != 1)
    {
        if(arr.find(m) == arr.end())
        {
            arr.insert(m);
            m = squares(m);
        }
        else
        {
            cout << "No" << endl;
            return 0;
        }
        

    }
    cout << "YES" << endl;
    return 0;


}