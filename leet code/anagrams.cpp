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

int main()
{
	test()
	{
        vector<string> strs;
        strs.push_back("eat");
        strs.push_back("tea");
        strs.push_back("tan");
        strs.push_back("ate");
        strs.push_back("nat");
        strs.push_back("bat");

        map<string,string> hash;
        for(int i=0; i<strs.size(); i++)
        {
            cout << strs[i] << endl;
        }
        for(int i=0; i<strs.size(); i++)
        {
            string st;
            st = strs[i];
            sort(strs[i].begin(),strs[i].end());
            hash.insert({strs[i], st});
            cout << strs[i] << endl;
            cout << st << endl;
        }
        cout << "KEY\tELEMENT\n"; 
        for (auto itr = hash.begin(); itr != hash.end(); ++itr) { 
            cout << itr->first 
                << '\t' << itr->second << '\n'; 
    } 

	}

}