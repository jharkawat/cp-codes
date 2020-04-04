#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test() int t;cin>>t;while(t--)
#define ll long long
#define For(_i , N) for(int _i = 0 ;_i < N ; _i ++)
#define ForR(_i , N) for(int _i = N ;_i > 0 ; _i --)
#define ForI(_i , a , N) for(int _i = a ;_i < N ; _i ++)
#define ForIR(_i , a , N) for(int _i = N ;_i > a ; _i --)
#define INF (2139062143)

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


int main()
{
	test()
	{
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll count = 0;
        ll nos = n/k;
        ll arr[nos];
        ll max1;
        char a;
        char transfer1, transfer2;
        string temp, temp1, final;        
        ll ch1[26];        
        for(int i = 0; i<=k/2; i++)
        {
            for(int j=0; j<nos; j++)
            {
                transfer1 = s[j*k + i];
                temp[j] = transfer1;
                cout << temp << endl;
                transfer2 = s[(j+1)*k-(i+1)];
                temp1[j] = transfer2;
            }
            cout << transfer1 << endl;
            if((k%2 != 0) && (i = k/2))
            {
                final = temp;
            }
            else 
            {
                final = temp + temp1;
            }
            debug(final);

            if((k%2 != 0) && (i = k/2))
            {
                for(k = 0; k< nos; k++)
                {
                    ch1[final[k]-97]++;
                }
            }
            else
            {
                for(k = 0; k< 2*nos; k++)
                {
                    ch1[final[k]-97]++;
                }
            }
            

            max1 = max_element(ch1, ch1 + 26) - ch1;
            a = 'a' + max1;
            if((k%2 != 0) && (i = k/2))
            {
                for(int j=0; j<nos; j++)
                {
                    if(final[j] != a)
                    {
                        count++;
                    }
                }
            }
            else
            {
                for(int j=0; j<2*nos; j++)
                {
                    if(final[j] != a)
                    {
                        count++;
                    }
                }
            }
            
        }
        debug(nos,temp, temp1, final, max1, count);

	}
    return 0;

}
        // For(i,nos)
        // {
        //     arr[i] = 0;
        // }
        // For(i,nos)
        // {
        //     For(j,k/2)
        //     {
        //         if(s[i*k+j] == s[(i+1)*k-(j+1)])
        //         {
        //             arr[i]++;
        //         }
        //     }
        // }
        // ll index = max_element(arr, arr + nos) - arr;
        // for(i = k*index;i<k*(index+1);i++)
        // {
        //     ll col;
        //     for(j=0; j<nos; j++)
        //     {
        //         string temp, temp1;
        //         temp[j] = s[j*k];
        //         temp1[j] = s[(j+1)*k];
        //     }
        //     ll ch1[26], ch2[26];
        //     for(k = 0; k<nos; k++)
        //     {
        //         ch1[temp[k]-97]++;
        //         ch2[temp1[k]-97]++;
        //     }
        //     ll max1 = max_element(ch1, ch1 + 26) - ch1;
        //     ll max2 = max_element(ch2, ch2 + 26) - ch2;
        //     if(ch1(max1) >= 2 || ch2(max2) >= 2)
        //     {
        //         if(ch1(max1) >= ch2(max2) )
        //         {
        //             string a;
        //             a = 'a' + max1;
        //             for(j=0; j<nos; j++)
        //             {
        //                 if(temp[j] != a)
        //                 {
        //                     count++;
        //                 }
        //                 if(temp1[j] != a)
        //                 {
        //                     count++
        //                 }
        //             }
        //         }
        //         else
        //         {
        //             string a;
        //             a = 'a' + max2;
        //             for(j=0; j<nos; j++)
        //             {
        //                 if(temp[j] != a)
        //                 {
        //                     count++;
        //                 }
        //                 if(temp1[j] != a)
        //                 {
        //                     count++
        //                 }
        //             }
        //         }
        //     }
        //     else if()

        // }
