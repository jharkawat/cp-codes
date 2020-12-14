#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> coin;
        for(int i = 0; i<n; i++)
        {
            int p;
            cin >> p;
            coin.push_back(p);
        }
        int sum;
        cin >> sum;
        int dp[n+1][sum+1];
        memset(dp, -1, sizeof dp);
        for(int i=0; i<=n; i++)
        {
            dp[i][0] = 1;
        }
        for(int i=1; i<=sum; i++)
        {
            dp[0][i] = 0;
        }
        for(int i = 1; i<=n; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                if(coin[i-1] <= j)
                {
                    dp[i][j] = dp[i][j-coin[i-1]]+dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
                cout << dp[i][j] << " " << i << " " << j << endl;

            }
        }
        cout << dp[n][sum] << endl;
    }
	return 0;
}