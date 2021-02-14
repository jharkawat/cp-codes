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

ll binary_search(ll start, ll end, vector<ll> &vec)
{
    ll mid = (end-start)/2 + start;
    //debug(mid);
    if((vec[mid]<vec[mid-1]) || (vec[mid]>vec[mid+1]))
    {
        return mid;
    }
    else
    {
        binary_search(start,mid-1,vec);
        binary_search(mid+1,end,vec);
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    ll n;
    cin >> n;
    vector<ll> vec;
    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >>t;
        vec.push_back(t);
    }
    ll start = 0;
    ll end = n-1;
    if(n==2)
    {
        if(vec[0]>vec[1])
        {
            cout << "yes" << endl;
            cout << "1 2" << endl;
            return 0;
        }
        else
        {
            cout << "yes" << endl;
            cout << "1 1" << endl;
            return
        }

    }    
    ll index=binary_search(start,end,vec);
    if(index==-1)
    {
        cout << "yes" << endl;
        cout << "1 1" << endl;
    }
    else
    {
        ll i = index, j=index;
        ll flag1 = 1, flag2 = 1;
        while(flag1 || flag2)
        {
            if((vec[i]<vec[i-1]) && (i!=0))
            {
                i--;
            }
            else
            {
                flag1=0;
            }
            if((vec[j]>vec[j+1]) && (j<n-1) && (j!=0))
            {
                j++;
            }
            else
            {
                flag2=0;
            }
        }
        //debug(i,j);
        for(int k =0; k<=(j-i)/2; k++)
        {
            swap(vec[i+k],vec[j-k]);
        }
        for(int k=0; k<n-1; k++)
        {
            if(vec[k]>vec[k+1])
            {
                cout << "no" << endl;
                return 0;
            }
        }
        cout << "yes" << endl;
        //debug(i,j);
        cout << (i+1) << " " << (j+1) << endl;
        return 0;
    }
}