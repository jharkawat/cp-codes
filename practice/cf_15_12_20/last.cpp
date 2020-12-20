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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    ll t;
    cin >> t;
    For(i,t)
    {
        ll n;
        cin >> n;
        string str;
        cin >> str;
        if(str[0]=='2' && str[1]=='0' && str[2]=='2' && str[3]=='0')
        {
            cout << "YES" << endl;
        }
        else if(str[0]=='2' && str[1]=='0' && str[2]=='2' && str[n-1]=='0')
        {
            cout << "YES" << endl;
        }
        else if(str[0]=='2' && str[1]=='0' && str[n-2]=='2' && str[n-1]=='0')
        {
            cout << "YES" << endl;
        }
        else if(str[0]=='2' && str[n-3]=='0' && str[n-2]=='2' && str[n-1]=='0')
        {
            cout << "YES" << endl;
        }
        else if(str[n-4]=='2' && str[n-3]=='0' && str[n-2]=='2' && str[n-1]=='0')
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}