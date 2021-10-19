#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n,k; 
    cin >> n >> k;
    vector<ll> vec(n);
    ll zero = 0;
    for(ll i=0; i<n; i++)
    {
        cin >> vec[i];
        if(vec[i]==0) zero =1;
    } 
    if(k == 0)
    {
        if(zero) cout << "-1\n";
        else cout << "0\n";
        return;
    }
    // queue<int> flips;
    // int res=0;
    // for (auto i = 0; i < vec.size(); ++i) {
    // 	if (vec[i] != (flips.size() % 2 ? 0 : 1)) 
    //     {
    //         // cout << "here\n";
    //     	++res;
    //     	flips.push(i + k - 1);
    // 	}
    // 	if (!flips.empty() && flips.front() <= i) flips.pop();
    // }
    // if(flips.empty())
    // cout << res << endl;
    // else 
    // cout << "-1\n";


    queue<ll> qu;
    bool flag = true;
    ll counts = 0;
    for(ll i=0; i<n; i++)
    {
        if(i<=(n-k))
        {
            if((vec[i]+(ll)qu.size()%2)%2 == 0)
            {
                qu.push(i+k-1);
                counts++;
            }
            if(!qu.empty() && qu.front()==i)
            {
                qu.pop();
            }
        }
        else
        {
            if((vec[i]+(ll)qu.size()%2)%2 == 0)
            {
                flag = false;
            }
            if(!qu.empty() && qu.front()==i)
            {
                qu.pop();
            }
        }
    }    
    if(flag)
    {
        cout << counts << "\n";
    }
    else
    {
        cout << "-1\n";
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