#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

void generate(string s, int level, set<string> &ans)
{
    if(level==2)
    {
        ans.insert(s);
    }
    else
    {
        for(int i=0; i<(int)s.size(); i++)
        {
            for(int j=i+1; j<=(int)s.size();j++)
            {
                reverse(s.begin()+i, s.begin()+j);
                generate(s,level+1,ans);
                reverse(s.begin()+i, s.begin()+j);
            }
        }
    }
}

void solve()
{
    string S,T;
    cin >> S >> T;
    set<string> forward,backward;
    generate(S,0,forward);
    generate(T,0,backward);
    for(auto x:forward)
    {
        // cout << x << endl;
        if(backward.find(x)!=backward.end())
        {
            cout << "YES" <<"\n";
            // cout << x << endl;
            return;
        }
    }
    cout << "NO" <<"\n";
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}