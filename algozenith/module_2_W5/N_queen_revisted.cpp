#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n;
vector<ll> queens;
ll ans =0;

bool check(int row, int col)
{
    for(int i=0; i<row; i++)
    {
        int pcol = queens[i];
        if((pcol == col) || (abs(pcol-col) == abs(i-row)) || (abs(pcol-col)<3 && abs(i-row)<3))
        {
            return false;
        }
    }
    return true;
}

void solve(int level)
{
    if(level == n)
    {
        ans++;
    }
    for(int i=0; i<n ;i++)
    {
        if(check(level,i))
        {
            queens.push_back(i);
            solve(level+1);
            queens.pop_back();
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
    solve(0);
    cout << ans << "\n";
}