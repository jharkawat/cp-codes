#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n;
ll depth = 0;
string ans = {};

void solve(int level, int depth)
{

    if((level == n))
    {
        if((depth == 0)) cout << ans << "\n";
        return;
    }
    else
    {
        ans += "(";
        // cout << "here" << endl;
        solve(level+1,depth+1);
        ans.pop_back();
        if(depth) {
            ans += ")";
            solve(level+1,depth-1);
            ans.pop_back();
        }
    }
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin >> n;
    solve(0,0);
}