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

vector<int> subUnsort(vector<int> &A) 
{
    vector<int > fin = {-1};
    int small = -1; 
    int large = -1;
    int stag = 1;
    int flag = 1;
    int i=0;
    int j= A.size()-1;
    int total = A.size();
    for(int k = 0; k<A.size(); k++)
    {
        if(A[i]>A[i+1] && (i<A.size()-2) && stag)
        {
            small = A[i+1];
            i++;
            stag = 0;
        }
        else if(stag)
        {
            i++;
        }
        if((A[j]<A[j-1]) && (j>0) && flag)
        {
            large = A[j-1];
            j--;
            flag = 0;
        }
        else if(flag)
        {
            j--;
        }
        if((small != -1) && i<A.size()-1)
        {
            //debug(small, A[i]);
            if(small > A[i])
            {
                small = A[i];
            }
            //debug(small);
            i++;
        }
        if((large != -1) && j>-1)
        {
            //debug(large);
            large = max(large, A[j]);
            j--;
        }
        
    }
    //debug(small,large);
    if(small == -1)
    {
        return fin;
    }
    else
    {
        stag = 1;
        flag = 1;
        i = 0;
        j = A.size()-1;
        while(stag || flag)
        {
            if((A[i] > small) && stag)
            {
                //debug(i);
                stag = 0;
            }
            else if(stag)
            {
                i++;
            }
            if((A[j] < large) && flag)
            {
                //debug(j);
                flag = 0;
            }
            else if(flag)
            {
                j--;
            }
        }
    }
    fin.erase(fin.begin() + 0);
    fin.pb(i);
    fin.pb(j);
    return fin;
    
}


// Driver Program 
int main() 
{ 
	// read only array, not to be modified 
	vector<int >arr = {  1, 1, 2, 3, 3, 4, 8, 9, 11, 9, 11, 12, 12, 11, 9, 14, 19, 20, 20 }; 

    vector<int > ar;
    ar = subUnsort(arr);

    for(int i=0; i<ar.size(); i++)
    {
        cout << ar[i] << endl;
    }
    
} 
