#include<bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

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
    bool ispalindrome(string str)
    {
        int m = str.size();
        for(int i = 0; i<m/2; i++)
        {
            if(str[i] != str[m-i-1])
            return false;
        }
        return true;
    }
	test()
	{     
        string p;
        cin >> p;
        int size = p.size();
        p[1] = p[1] + 2;
        cout << p << endl;
        int count = 1;
        if(ispalindrome(p))
        {
            if(m%2 != 0)
            {
                p[m/2] = p[m/2] + 1;
            }
            else 
            {
                p[m/2] = p[m/2] + 1;
                p[(m/2) - 1] = p[(m/2) - 1] + 1;
            }
        }
        else
        {
            for(int i = m/2; i>0 ; i--)
            {
                if((s[i-1] != s[m-i]) && count)
                {

                }
            }
        }
        



	}
}