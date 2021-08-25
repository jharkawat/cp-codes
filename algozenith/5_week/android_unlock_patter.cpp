#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
ll n;
ll arr[3][3]; 
vector<pair<int,int>> vec;

bool check(int curr_row, int curr_col, int row, int col)
{
    if(curr_row == 0 && curr_col == 0)
    {
        if((row == 1 && col == 2) || (row == 2 && col == 1))
        {
            return false;
        }

    }
    else if(curr_row == 0 && curr_col == 1){}
    else if(curr_row == 0 && curr_col == 2){}
    else if(curr_row == 1 && curr_col == 0){}
    else if(curr_row == 1 && curr_col == 1){}
    else if(curr_row == 1 && curr_col == 2){}
    else if(curr_row == 2 && curr_col == 0){}
    else if(curr_row == 2 && curr_col == 1){}
    else if(curr_row == 2 && curr_col == 2){}

}
ll ans = 0;
void solve(int level, int row, int col)
{
    if(level == n)
    {
        ans++;
    }
    else
    {
        for(auto x: vec)
        {
            check()
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
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            vec.push_back({i,j});
        }
    }
    solve(0,0,0);

}   