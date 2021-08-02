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
#define N (1000000007)

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
    ll n;
    cin >> n;
    vector<ll> numbers(n);
    for(ll i =0; i<n; i++)
    {
        cin >> numbers[i];
    } 
    ll count=0;
    ll diff;
    sort(numbers.begin(), numbers.end());
    if(n==1)
    {
        cout << "-1" << endl;
    }
    else if(n==2)
    {
        for(ll i=1; i<n; i++)
        {
            if(numbers[i]==numbers[i-1])
            {
                if(numbers[0]==numbers[n-1])
                {
                    cout << "1" << endl;
                    cout << numbers[0] << endl;
                    return 0;
                }
                else
                {
                    cout << "0" << endl;
                    return 0;
                }
            }
        }    
        diff = abs(numbers[1]-numbers[0]);
        if(diff>1)
        {
            cout << "3" << endl;
            cout << numbers[0]-diff << " " << (numbers[1]+numbers[0])/2 << " " << numbers[1]+diff << endl;
        }
    }
    else if(n==3)
    {
        for(ll i=1; i<n; i++)
        {
            if(numbers[i]==numbers[i-1])
            {
                if(numbers[0]==numbers[n-1])
                {
                    cout << "1" << endl;
                    cout << numbers[0] << endl;
                    return 0;
                }
                else
                {
                    cout << "0" << endl;
                    return 0;
                }
            }
        }
        if((numbers[2]-numbers[1]) == (numbers[1]-numbers[0]))
        {
            diff = abs(numbers[1]-numbers[0]);
            cout << "2" << endl;
            cout << numbers[0]-diff << " " << numbers[2]+diff << endl;
        }
        else
        {
            ll diff2 = abs(numbers[2]-numbers[1]);
            diff = abs(numbers[1]-numbers[0]);
            if(diff2 == diff*2)
            {
                cout << "1" << endl;
                cout << (numbers[1]+numbers[2])/2 << endl;

            }
            else if(diff == diff2*2)
            {
                cout << "1" << endl;
                cout << (numbers[1]+numbers[0])/2 << endl;
            }
        }
    }
    else
    {
        ll diff2, diff3, diff1;
        diff2 = -1;
        diff3 = -1;
        ll count1 = 0;
        ll count2 = 0;
        ll p;
        diff1 = abs(numbers[1]-numbers[0]);
        for(ll i=1; i<n; i++)
        {
            if(numbers[i]==numbers[i-1])
            {
                if(numbers[0]==numbers[n-1])
                {
                    cout << "1" << endl;
                    cout << numbers[0] << endl;
                    return 0;
                }
                else
                {
                    cout << "0" << endl;
                    return 0;
                }
            }
            diff=abs(numbers[i]-numbers[i-1]);
            if(diff != diff1)
            {
                diff2 = diff;
                count2++;
                p = i;
            }
            else if(diff != diff1 && diff != diff2)
            {
                cout << "-1" << endl;
                return 0;
            }
            else
            {
                count1++;
            }
        }
        if(diff2 == -1)
        {
            cout << "2" << endl;
            cout << numbers[0]-diff << " " << numbers[n-1]+diff << endl;
        }
        else if(count1>1 && count2>1)
        {
            cout << "-1" << endl;
        }
        else if(diff2 == diff1*2)
        {
            cout << "1" << endl;
            cout << (numbers[p]+numbers[p-1])/2 << endl;

        }
        else if(diff1 == diff2*2)
        {
            cout << "1" << endl;
            cout << (numbers[1]+numbers[0])/2 << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
}