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
    ll m,s;
    cin >> m >> s;
    string mins(m,'0');
    mins[0]='1';
    string maxs(m,'0');   
    ll sum = s-1;
    if(s==0 && m==1)
    {
        cout << "0 0" << endl;
    }
    else if(s==1 )
    {
        string minss(m,'0');
        string maxss(m,'0');
        minss[0]='1';
        maxss[0]='1';
        cout << minss << " " << maxss << endl;   

    }
    else if(m*9<s || s==0)
    {
        cout << "-1 -1" << endl;
    }
    else
    {
        for(int i=m-1; i>=0;i--)
        {
            sum = sum-9;
            if(sum>0)
            {
                mins[i]=mins[i]+9;
            }    
            else
            {
                sum = sum+9;
                mins[i] = mins[i] + sum;
                break;
            }
        }
        for(int i=0; i<m;i++)
        {
            s = s-9;
            if(s>=0)
            {
                maxs[i]=maxs[i]+9;
            }    
            else
            {
                s = s+9;
                maxs[i] = maxs[i] + s;
                break;
            }
        }
        cout << mins << " " << maxs << endl;
    }
}