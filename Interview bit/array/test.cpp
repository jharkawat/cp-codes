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

ll value_r(vi b, ll start, ll end, ll act_val)
{
    ll rsv = 0;
    for(ll i = start; i<end; i++)
    {
        if((ll)b[i] > act_val)
        {
            rsv = i;
            break;
        }
    }
//    debug(rsv);
    return rsv;
}

ll value_l(vi b, ll start, ll end, ll act_val)
{
    ll rsv = 0;
    for(ll i = end; i>=start; i--)
    {
        if((ll)b[i] > act_val)
        {
            rsv = i;
            break;
        }
    }
//    debug(rsv);
    return rsv;
}

int maxSpecialProduct(vector<int> &A) 
{
//    cout << "in max" << endl;
    ll max = 0;
    ll prod = 0;
    for(int i; i<A.size(); i++)
    {
//        cout << "in max for" << endl;
        ll left = value_l( A, 0, i, (ll)A[i]);
        ll right = value_r(A, i, A.size(), (ll)A[i]);        
        prod = left*right;
//        debug(left,right,prod);
        if(prod>max)
        {
            max = prod;
        }
    }
    return max;
    
}

int main()
{
    // vector<int > vec = { 5, 9, 6, 8, 6, 4, 6, 9, 5, 4, 9};
    // int m = maxSpecialProduct(vec);
    // cout << "return value : " << m << endl;
    // cout << vec.size() << endl;
    // for(int i = 0; i< vec.size() ; i++)
    // {
    //     cout << vec[i] << " " ;

    // } 
    // cout << endl;

    vector<string > v = {"3", "31", "34", "5", "9"};
    cout << v[1][4]<< endl;
    sort(v.begin(), v.end(),greater<string>());
    for(int i = 0; i< v.size() ; i++)
    {
        cout << v[i] << " " ;

    }    
    return 0;
}