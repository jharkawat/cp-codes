#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define For(_i , N) for(int _i = 0 ;_i < N ; _i ++)
#define ForR(_i , N) for(int _i = N ;_i > 0 ; _i --)
#define ForI(_i , a , N) for(int _i = a ;_i < N ; _i ++)
#define ForIR(_i , a , N) for(int _i = N ;_i > a ; _i --)
#define INF (2139062143)

bool check(string s)
{
    int si = s.size();
    For(j,si)
    {
        if(s[j] != '9')
        return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    For(i,t)
    {
        ll a,b;
        cin >> a >> b;
        //cout << ma << endl;
        string str = to_string(b);
        int s =  str.size();
        //cout << "s " << s<< endl;
        //cout << s << endl;
        if(str[0] == '9')
        {
            if(check(str))
            cout << a*s << endl;
            else
            cout << a*(s-1) << endl;
        }
        else
        cout << a*(s-1) << endl;
    }
}