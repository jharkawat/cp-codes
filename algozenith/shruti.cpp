#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
k = 3

0 1 2 3 4 5 6 7 8 9
1 2 4 5 7 8 9 10

index = 0, 3, 7, 6  
siz = 10 , 9 ,8, 7   
conditions
*/
ll n,k; 
vector<ll> pos; 

ll kills(ll index, ll siz)
{
    if(siz==1)
    {
        return index;
    }
    else
    {
        return kills((index + (k-1))%n, siz--) + 1; 
    }
}

void solve()
{ 
    cin >> n >> k; 
    for(ll i=0; i<n; i++)
    {
        pos.push_back(i);
    }    
    cout << kills(0,n)+1 << endl;
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();

    // ll t; cin >> t; 
    // while(t--)
    // {
    //     solve();
    // }
}