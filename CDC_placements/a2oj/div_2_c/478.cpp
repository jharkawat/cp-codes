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
    ll r,g,b;
    cin >> r >> g >> b;
    ll count; 
    ll min1, min2, min3;
    if(r>=g)
    {
        if(b>=r)
        {
            min1=g;
            min2=r;
            min3=b;
        }
        else
        {
            if(b>=g)
            {
                min1=g;
                min2=b;
                min3=r;
            }
            else
            {
                min1=b;
                min2=g;
                min3=r;
            }
        }
    }
    else
    {
        if(b>=g)
        {
            min1=r;
            min2=g;
            min3=b;
        }
        else
        {
            if(b>=r)
            {
                min1=r;
                min2=b;
                min3=g;
            }
            else
            {
                min1=b;
                min2=r;
                min3=g;
            }
        }

    }
    // debug(min1);
    // debug(min2);
    // debug(min3);
    if(min3>=min1+min2 && min1 >0)
    {
        ll ans = min1+min2;
        cout << ans*2/3 << endl;
        return 0;
    }
    if(min2 ==0 && min1 ==0)
    {
        cout << "0" << endl;
        return 0;
    }
    else
    {
        count = min1;
        min2-=min1;
        min3-=min1;
        count += (min2/3)*2;
        ll a = min3-min2; 
        //debug(a);
        if(a>=4 && (min2%3)==2)
        {
            count += 2;
        }
        else if(a>=4 && (min2%3)==1)
        {
            count += 1;
        }
        else if(a<=3 && (min2%3)!=0 && a>0)
        {
            count +=1;
        }
        cout << count << endl;
    }
}