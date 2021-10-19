// #include <bits/stdc++.h>
// using namespace std;
// int prefSum[1000001][31];
// int main()
// {
//    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//     #ifndef ONLINE_JUDGE
//     freopen("../input.txt", "r", stdin);
//     freopen("../output.txt", "w", stdout);
//     #endif

//    int testcases;
//    cin>>testcases;
//    while(testcases--)
//    {
//        int n,q;
//        int i;
//        cin>>n;
//        for(i=0;i<=n;i++)
//          for(int j = 0;j<31;j++)
//            prefSum[i][j]=0;
//        for(i=1;i<=n;i++)
//        {
//          int a;
//          cin>>a;
//          int cnt = 0;
//          while(a>0)
//          {
//            prefSum[i][cnt]=a%2;
//            a/=2;
//            cnt++;
//          }
//        }
//        for(i=1;i<=n;i++)
//        {
//          for(int j=0;j<31;j++)
//            prefSum[i][j]+=prefSum[i-1][j];
//        }
//        for(i=0;i<=n;i++)
//        {
//          for(int j=0;j<31;j++)
//            cout << prefSum[i][j];
//         cout << endl;
//        }

//        cin>>q;
//        while(q--)
//        {
//          int l,r;
//          cin>>l>>r;
//          double total=(r-l+1.0)/(2);
//          long long x1 = 0,x2 = 0,x3 = 0;
//          for(i=0;i<31;i++)
//          {
//            int p = prefSum[r][i]-prefSum[l-1][i];
//            if(p<total)
//              x1+=(1LL<<i);
//            if(p!=(r-l+1))
//              x2+=(1LL<<i);
//            if(p)
//              x3+=(1LL<<i);
//          }
//          long long ans = x1+x2+x3;
//         cout << x1 << " " << x2 << " " << x3 << " \n";

//          cout<<ans<<"\n";
//        }
//    }
// }

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
    ll arr[n];
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }    
    ll mat[31][n+1];
    memset(mat,0,sizeof(mat));

    for(ll i=0; i<31; i++)
    {
        for(ll j=0; j<n; j++)
        {
            if(arr[j]&(1LL<<i))
            {
                // cout << "here\n";
                mat[i][j+1] = 1+mat[i][j];
            }
            else
            {
                mat[i][j+1] = mat[i][j];
            }
        }
    }
    // for(ll i=0; i<31; i++)
    // {
    //     for(ll j=0; j<=n; j++)
    //     {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ll q;
    cin>> q;
    while(q--)
    {
        ll l,r;
        cin >> l >> r;
        ll x1=0,x2=0,x3=0;
        ll diff = r-l+1;
        double total=(r-l+1.0)/(2);
        ll x11=0,x21=0,x31=0;

        for(ll i=0; i<31; i++)
        {
            int p = mat[i][r]-mat[i][l-1];
            if(p<total)
                x11+=(1LL<<i);
            if(p!=(r-l+1))
                x21+=(1LL<<i);
            if(p)
                x31+=(1LL<<i);
               

            ll one,zero; 
            one = mat[i][r]-mat[i][l-1];
            zero = diff-one;
            if(one<zero)
            {
                x1|=(1LL<<i);
            }
            if(one) x3|=(1LL<<i);
            if(one != diff)
            {
                x2|=(1LL<<i);
            }
        }
        ll ans1 = (x11+x21+x31); 
        // cout << x11 << " " << x21 << " " << x31 << " \n";
        cout << ans1 << "\n";

        ll ans = (x1+x2+x3); 
        // cout << x1 << " " << x2 << " " << x3 << " \n";
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

    // solve();

    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}