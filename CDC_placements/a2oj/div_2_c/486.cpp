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

bool ispalindrome(string str)
{
    ll siz = str.length();
    ll j= siz-1;
    for(ll i=0; i<siz/2; i++)
    {
        j=j-i;
        if(str[i]!=str[j])
        {
            return false;
        }
    }    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    ll n,p;
    cin >> n >> p;
    p--;
    string str;
    cin >> str;
    if(p>=n/2)
    {
        str.reserve();
        p = n-p-1;
    }    
    ll mins, maxs;
    mins = p;
    maxs = p;
    ll count = 0; 
    ll j = n-1;
    for(ll i=0; i<n/2; i++)
    {
        if(str[i]!=str[j-i])
        {
            mins = min(mins,i);
            maxs = max(maxs,i);
            ll dist = abs(str[i]-str[j-i]);
            if(dist>13)
            {
                dist = 26-dist;
            }
            count += dist;
        }
    }
    //debug(count);
    if((maxs-p)<(p-mins))
    {
        count += 2*(maxs-p) + (p-mins);
    }
    else
    {
        count += 2*(p-mins) + (maxs-p); 
    }
    cout << count << endl;
}