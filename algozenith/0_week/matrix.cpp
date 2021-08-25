#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll n,m,p;
ll arr1[101][101], arr2[101][101], final[101][101];

void solve()
{
    cin >> n >> m >> p;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> arr1[i][j];
        }
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<p; j++)
        {
            cin >> arr2[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<p; j++)
        {
            for(int k=0; k<m; k++)
            {
                final[i][j] += arr1[i][k]*arr2[k][j];
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<p; j++)
        {
            cout << final[i][j] << " ";
        }
        cout << endl;
    }

}

signed main()
{
    IOS
    ll t; cin >> t;
    while(t--)
    {
        solve();
    }
}