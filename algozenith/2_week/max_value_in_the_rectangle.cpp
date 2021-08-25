#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n,m,q;
    cin >> n >> m >> q;
    ll arr[n+2][m+2];
    memset(arr,0,sizeof(arr));
    ll max = INT32_MIN, count =1;
    while(q--)
    {
        ll x1,x2,y1,y2,num;
        cin >> x1 >> y1 >> x2 >> y2 >> num;
        arr[x1][y1] += num;
        arr[x2+1][y2+1] += num;
        arr[x1][y2+1] -= num;
        arr[x2+1][y1] -= num;
    }
    for(ll i=2; i<=m; i++)
    {
        arr[1][i] += arr[1][i-1];
        if(arr[1][i] > max)
        {
            max = arr[1][i];
            count = 1;
        }
        else if(arr[1][i] == max)
        {
            count++;
        }
    }
    for(ll i=2; i<=n; i++)
    {
        arr[i][1] += arr[i-1][1];
        if(arr[i][1] > max)
        {
            max = arr[i][1];
            count = 1;
        }
        else if(arr[i][1] == max)
        {
            count++;
        }

    }
    for(ll i=2; i<=n; i++)
    {
        for(ll j=2; j<=m; j++)
        {
            arr[i][j] += (arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]);
            if(arr[i][j] > max)
            {
                max = arr[i][j];
                count = 1;
            }
            else if(arr[i][j] == max)
            {
                count++;
            }
        }
    }
    cout << max << " " << count << endl;
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    solve();
}