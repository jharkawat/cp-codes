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

vector<int> maxset(vector<int> &A) 
{
    vector<tuple<int, int, int> > vec;
    vi fin;
    ll sum = -1;
    ll max = 0;
    ll fst = -1;
    ll end;
    for(ll i = 0 ; i<A.size(); i++)
    {
        if(A[i] < 0)
        {
            fst = -1;
            sum = -1;
        }
        if((fst = -1) && (A[i]>0))
        {
            fst = i;
            sum = 0;
        }
        if(sum != -1)
        {
            sum += A[i];
        }
        if(max <= sum)
        {
            if(sum > max)
            {
                vec.erase(vec.begin(), vec.end());
            }
            max = sum;
            end = i;
            vec.pb(make_tuple(fst,end,(end-fst+1)));
        }
    }
    vector<int > sub;
    int start;
    if(vec.size() > 1)
    {
        int max = get<2>(vec[0]);
        int j = 0;
        for(int i=0; i<vec.size(); i++)
        {
            if(max <= get<2>(vec[i]))
            {
                if(max < get<2>(vec[i]))
                {
                    sub.erase(sub.begin(),sub.end());
                }
                sub.pb(i);
            }
        }
        if(sub.size()>1)
        {
            int start = get<0>(vec[sub[0]]);
            for(int i=0; i<sub.size(); i++)
            {
                if(start > get<0>(vec[sub[i]]));
                {
                    start = sub[i];
                }
            }
        }
        else 
        {
            start = sub[0];
        }
    }
    for(int i = get<0>(vec[start]); i<=(get<1>(vec[start])); i++)
    {
        fin.pb(A[i]);
    }
    return fin;
}

int main()
{
	vi vec = {1,2,5,-7,2,5};
    vi fin = maxset(vec);
    for(int i = 0 ; i<fin.size(); i++)
    {
        cout << fin[i] << endl;
    }
}