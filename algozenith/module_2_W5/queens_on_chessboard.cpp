#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

const long long n = 8;
vector<int> st[8]; 
vector<ll> queens;
ll ans = 0;

bool check(int row, int col)
{
    for(int i=0; i<row; i++)
    {
        int pcol = queens[i], prow = i;
        if((pcol == col) || (abs(pcol-col) == abs(prow-row)) || st[row][col])
        {
            return false;
        }
    }
    if(row == 0)
    {
        if(st[row][col])
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
        return;
    }

    for(int i=0; i<n; i++)
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

    for(int i=0; i<n; i++)
    {
        st[i].clear();
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            char temp; cin >> temp;
            if(temp == '.')
            {
                st[i].push_back(0);
            }
            else
            {
                st[i].push_back(1);
            }
        }
    }
    solve(0);
    cout << ans << "\n";
}