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
    vector<vector<int> > A{ { 1, 2, 3 }, 
                               { 4, 5, 6 }, 
                               { 7, 8, 9 },
                               { 10, 11, 12} }; 
    vector<int> vec;
    int m = A.size();
    int n = A[0].size();
    int total = m*n;
    int row_up = 0; 
    int row_low = 0;
    int col_up = 0; 
    int col_low = 0;
    int t;
    int row = 0;
    int col = 0;
    int j = 0;
    int i;
    while(total != 0)
    {
        if((row == 0) && (col == 0))
        {
            for(i = row_low; i<n-row_up; i++ )
            {
                int t = A[j][i];
                vec.push_back(t);
                total--;
            }
            j = i-1;
            col_low++;
            col = 1;

        }
        else if((row == 0) && (col == 1))
        {
            for(i = col_low; i<m-col_up; i++ )
            {
                int t = A[i][j];
                vec.push_back(t);
                total--;
            }            
            row_up++;
            j = i-1;
            row = 1;
        }
        else if((row == 1) && (col == 1))
        {
            for(i = n-row_up-1; i>= (0 + row_low); i-- )
            {
                int t = A[j][i];
                vec.push_back(t);
                total--;
            }
            col = 0;
            col_up++;
            j=i+1;
        }
        else
        {
            for(i = m-col_up-1; i>=(0+col_low); i-- )
            {
                int t = A[i][j];
                vec.push_back(t);
                total--;
            }
            row = 0;
            row_low++;
            j=i+1;
        }
        
    }
    
    for (auto i = vec.begin(); i != vec.end(); ++i) 
    cout << *i << " "; 
}