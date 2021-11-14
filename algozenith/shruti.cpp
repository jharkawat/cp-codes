#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <string>
#include <cmath>
using namespace std;
#define ll long long 
#define mod 1000000007
#define MAX 1000000

vector<int> vec;
int dp[1010][1010][505];
int p;

int rec(int x, int y, int level)
{
    if(level == p)
    {
        return 0;
    }

    if(dp[x][y][level] != -1)
    {
        return dp[x][y][level];
    }
    // cout << level << endl;

    int ans = 0; 
    if(vec[level]<=x) ans = max(ans,1+rec(x-vec[level],y,level+1));
    if(vec[level]<=y) ans = max(ans,1+rec(x,y-vec[level],level+1));
    ans = max(ans,rec(x,y,level+1));

    return dp[x][y][level] = ans;
}

int main(){
    int x,y;
    cin >> x >> y;
    cin >> p;
    for(int i=0; i<p; i++)
    {
        int k; cin >> k;
        vec.push_back(k);
    }
    // x=1;
    // y=1;
    // vec = {1,1,3};
    memset(dp,-1,sizeof(dp));
    int ans = rec(x,y,0);
    cout << ans << endl;
    return 0;
}