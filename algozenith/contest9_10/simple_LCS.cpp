#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
string str1, str2;
ll dp[1010][1010][2][2];
ll done[1010][1010][2][2];
ll m,n;

ll rec(ll level1, ll level2, ll a, ll b)
{
    // base case
    if(level1 == m || level2 == n)
    {
        if(a==0 && b==1)
        {
            // cout << level1 << " " << level2 << " "<< a << " "<< b << " yes \n";
            return 0;
        }
        else
        {
            // cout << level1 << " " << level2 << " "<< a << " "<< b << " yes2 \n";
            return -100000000;
        }
    }

    // cache
    if(done[level1][level2][a][b] != -1)
    {
        return dp[level1][level2][a][b];
    }

    // logic
    ll ans = 0; 
    if(str1[level1] == str2[level2])
    {
        ll p=a,q=b;
        if(str1[level1] == 'a')
        {
            p = a^1;
        }
        if(str1[level1] == 'b')
        {
            q = b^1;
        }
        ans = max({1+rec(level1+1,level2+1,p,q),rec(level1+1,level2,a,b),rec(level1,level2+1,a,b)});
    }
    else
    {
        ans = max({rec(level1+1,level2,a,b),rec(level1,level2+1,a,b)});
    }

    // save and return 
    done[level1][level2][a][b] = 1;
    // cout << level1 << " " << level2 << " "<< a << " "<< b << " "<< ans << "\n";
    return dp[level1][level2][a][b] = ans;
}

void solve()
{
    cin >> str1 >> str2;
    m = str1.size();
    n = str2.size();
    memset(done,-1,sizeof(done));
    ll ans = rec(0,0,0,0);
    if(ans<0)
    {
        cout << 0 << "\n";
    }  
    else
    {
        cout << rec(0,0,0,0) << '\n';
    }
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    // solve();

    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}