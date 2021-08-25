#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/

ll const mod = 1e9+7;

void solve()
{
    ll n,m,q;
    cin >> n >> m >> q;
    vector<vector<ll>> mat(n,vector<ll> (m,0));
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            cin >> mat[i][j];
        }
    }
    for(ll i=1; i<m; i++)
    {
        mat[0][i] += mat[0][i-1];
        mat[0][i] =  mat[0][i]%mod;
    }
    for(ll i=1; i<n; i++)
    {
        mat[i][0] += mat[i-1][0];
        mat[i][0] =  mat[i][0]%mod;
    }
    for(ll i=1; i<n; i++)
    {
        for(ll j=1; j<m; j++)
        {
            mat[i][j] += (mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1]+mod)%mod;
            mat[i][j] =  mat[i][j]%mod;
        }
    }
    while(q--)
    {
        ll x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll ans;
        if(x1 == 1 && y1 == 1)
        {
            ans = mat[x2-1][y2-1];
        }
        else if(x1 ==1)
        {
            ans = mat[x2-1][y2-1] - mat[x2-1][y1-2];
        }
        else if(y1 == 1)
        {
            ans = mat[x2-1][y2-1] - mat[x1-2][y2-1];
        }
        else
        {
            ans = mat[x2-1][y2-1] - mat[x1-2][y2-1] - mat[x2-1][y1-2] + mat[x1-2][y1-2];
        }
        ans = ans%mod;
        if(ans<0)
        {
            ans += mod;
        }
        cout << ans << "\n";
    }

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