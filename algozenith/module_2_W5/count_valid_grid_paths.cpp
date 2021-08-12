#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

string path;
vector<vector<int>> vec(7, vector<int>(7,0));

ll counts =0;
ll ans =0;
void solve(int row, int col)
{
    cout << counts << endl;
    cout << row << " " << col << endl;
    if(counts == 48)
    {
        if(row == 6 && col == 0) ans++;
        else return;
    }
    else
    {
        if(path[counts]=='?')
        {
            if(row+1<7 && vec[row+1][col] == 0)
            {
                counts++;
                vec[row+1][col] = 1;
                solve(row+1,col);
                counts--;
                vec[row+1][col] = 0;
            }
            else if(row-1>-1 && vec[row-1][col] == 0)
            {
                counts++;
                vec[row-1][col] = 1;
                solve(row-1,col);
                counts--;
                vec[row-1][col] = 0;
            }
            else if(col-1>-1 && vec[row][col-1] == 0)
            {
                counts++;
                vec[row][col-1] = 1;
                solve(row,col-1);
                counts--;
                vec[row][col-1] = 0;
            }
            else if(col+1<7 && vec[row][col+1] == 0)
            {
                counts++;
                vec[row][col+1] = 1;
                solve(row,col+1);
                counts--;
                vec[row][col+1] = 0;
            }
        }
        else if(path[counts]=='U')
        {
            if(col-1<0 || vec[row][col-1] == 1)
            {
                return; 
            }
            else
            {
                counts++;
                vec[row][col-1] = 1;
                solve(row,col-1);
                counts--;
                vec[row][col-1] = 0;
            }
        }
        else if(path[counts]=='D')        
        {
            if(col+1>6 || vec[row][col+1] == 1)
            {
                return; 
            }
            else
            {
                counts++;
                vec[row][col+1] = 1;
                solve(row,col+1);
                counts--;
                vec[row][col+1] = 0;
            }
        }
        else if(path[counts]=='L')
        {
            if(row-1<0 || vec[row-1][col] == 1)
            {
                return; 
            }
            else
            {
                counts++;
                vec[row-1][col] = 1;
                solve(row-1,col);
                counts--;
                vec[row-1][col] = 0;
            }
        }

        else if(path[counts]=='R')
        {
            if(row+1>6 || vec[row+1][col] == 1)
            {
                return; 
            }
            else
            {
                counts++;
                vec[row+1][col] = 1;
                solve(row+1,col);
                counts--;
                vec[row+1][col] = 0;
            }
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

    cin >> path;
    vec[0][0]=1;
    solve(0,0);
    cout << ans << endl;
}