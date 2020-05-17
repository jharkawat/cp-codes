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

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef pair< long long int ,long long int > iil;
 
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( auto i = (c).begin(); i != (c).end(); i++)
 
#define edl '\n'
#define ll long long 
#define ff first
#define ss second

int main()
{
    int t;
    cin >> t;
    For(i,t)
    {
        ll n;
        cin >> n;
        vector<ll> value;
        For(j,n)
        {
            int t ;
            cin >> t;
            value.pb(t);   
        }
        ll count = 0, a =0, b =0;
        int flag = 1;
        ll sum = 0;
        ll ret = 0;
        while(value.size())
        {
            ll c = 0;
            ll d = value.size()-1;
            ll sum1 = 0, sum2 = 0;
            if(flag == 1)
            {
                sum1 = ret;
                sum1 += value[c];
                a += value[c];
                value.erase(value.begin()+c);
                if(sum1>sum)
                {
                    sum = sum1;
                    count++;
                    flag = 0;
                    ret = 0;
                }
                else
                {
                    ret = sum1;
                    flag = 1;
                    if(c == d)
                    {
                        count++;
                    }
                }
            }
            else
            {
                sum2 = ret;
                sum2 += value[d];
                b += value[d];
                value.pop_back();
                if(sum2>sum)
                {
                    sum = sum2;
                    count++;
                    flag = 1;
                    ret = 0;
                }
                else
                {
                    ret = sum2;
                    flag = 0;
                    if(d == c)
                    {
                        count++;
                    }

                }

            }
            //debug(sum,sum1,sum2,ret, a,b,count);
        }

        cout << count << " " << a << " " << b << endl;
    }
}