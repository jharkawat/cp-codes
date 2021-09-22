#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n; cin >> n;
    ll mat[n][n];
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
        {
            cin >> mat[i][j];
        }
    }
    ll rem[n];
    for(ll i=0; i<n; i++)
    {
        cin >> rem[i];
        rem[i]--;
    }
    vector<ll> ans;
    for(ll k=n-1; k>=0; k--)
    {
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<n; j++)
            {
                mat[i][j] = min(mat[i][j], mat[i][rem[k]]+mat[rem[k]][j]);
            }
        }

        ll temp = 0;
        for(ll i=k; i<n; i++)
        {
            for(ll j=k; j<n; j++)
            {
                // cout << temp << " " << k << " " << rem[i] << "  " << rem[j] <<  "  " << mat[rem[i]][rem[j]] << endl;
                temp += mat[rem[i]][rem[j]];
            }
        }
        ans.push_back(temp);
    }

    reverse(ans.begin(), ans.end());
    for(ll i=0; i<n; i++)
    {
        cout << ans[i] << " ";
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