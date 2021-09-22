#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll m,n,q;
    cin >> n >> m >> q;
    ll mat[505][505];
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            mat[i][j] = 1e18;
        }
    }

    for(ll i=0; i<m; i++)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        mat[a][b] = min(mat[a][b],c);
        mat[b][a] = min(mat[b][a],c);
    }

    // for(ll i=1; i<=n; i++)
    // {
    //     for(ll j=1; j<=n; j++)
    //     {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    for(ll k=1; k<=n; k++)
    {
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=n; j++)
            {
                mat[i][j] = min(mat[i][j],(mat[i][k]+mat[k][j]));
            }
        }
    }

    for(ll i=0; i<q; i++)
    {
        ll a,b;
        cin >> a >> b;
        if(mat[a][b] >= 1e18) cout << "-1\n";
        else cout << mat[a][b] << endl;
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

    // ll t; cin >> t; 
    // while(t--)
    // {
    //     solve();
    // }
}