#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll l,r;
    ll arr[1000100];
    cin >> l >> r;
    vector<ll> is_prime;
    for(ll i = 0; i<1000100; i++)
    {
        arr[i]=1;
    }
    // cout << "here" << endl;
    for(ll i = 2; i*i<=r; i++)
    {
        if(arr[i]==1)
        {
            is_prime.push_back(i);
            for(ll j= i*i; j<1000100; j+=i)
            {
                arr[j]=0;
            }
        }
    }
    ll count = 0;
    ll ans[r-l+1];
    for(ll i = 0; i<r-l+1; i++)
    {
        ans[i]=1;
    }

    for(auto x : is_prime)
    {
        if(x*x>=r)
        {
            break;
        }
        ll curval = ((l+x-1)/x)*x;
        while(curval<=r)
        {
            if(curval != x && ans[curval-l] == 1)
            {
                // cout << "curval = " << curval << endl; 
                count++;
                ans[curval-l] = 0;
            }
            curval += x;
        }
    }
    if(l==1)
    {
        ans[0] = 0;
        count++;
    }
    cout << r-l+1-count << endl;
    for(ll i=0; i<r-l+1; i++)
    {
        if(ans[i]==1)
        {
            cout << i+l << " "; 
        }
    }
    cout << "\n";
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