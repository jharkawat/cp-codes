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
#define For(_i , N) for(int _i = 0 ;_i < N ; _i ++)
#define ForR(_i , N) for(int _i = N ;_i > 0 ; _i --)
#define ForI(_i , a , N) for(int _i = a ;_i < N ; _i ++)
#define ForIR(_i , a , N) for(int _i = N ;_i > a ; _i --)
#define INF (2139062143)

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef pair< long long int ,long long int > iil;
 
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( auto i = (c).begin(); i != (c).end(); i++)
 
#define edl '\n'
#define ll long long int
#define ff first
#define ss second

void setss(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<pair<int,int>> pi;
    int m = A.size();
    int n = A[0].size();
    debug(m,n);
    vector<int> vec(n,0);
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(A[i][j] == 0)
            {
                pi.push_back(make_pair(i,j));
                debug(i,j);
            }
        }
    }
    int run = pi.size();
    debug(run);
    for(int i = 0; i<run; i++)
    {
        debug(pi[i].first,pi[i].second);
        for(int j = 0; j<n; j++)
        {
            A[pi[i].first][j] = 0;
        }
        for(int k = 0; k<m; k++)
        {
            A[k][pi[i].second] = 0;
        }

    }

    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    
}

int main()
{
    
    vector<vector<int> > A ={{1,1,1,1},{1,1,1,1},{1,1,0,0}};
    setss(A);
    return 0;
}
