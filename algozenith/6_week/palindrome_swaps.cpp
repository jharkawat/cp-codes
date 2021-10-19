#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    ll n ; cin >> n;
    string str; cin >> str;
    ll counts = 0;
    ll l = 0, r = n-1;
    bool flag = true;
    ll arr[26];
    memset(arr,0,sizeof(arr));
    for(auto x : str)
    {
        arr[x-'a']++;
    }
    ll odd = 0;
    for(ll i=0; i<26; i++)
    {
        if(arr[i]%2 != 0)
        {
            odd++;
        }
    }
    if(odd)
    {
        if(n%2 == 0) 
        {
            cout << "-1\n";
            return;
        }
        else if(odd > 1)
        {
            cout << "-1\n";
            return;
        }
    }
    while(l<r)
    {
        if(str[l] == str[r])
        {
            l++;
            r--;
        }
        else 
        {
            ll a = 1e18,b = 1e18;
            for(ll i=l+1; i<r; i++)
            {
                // cout << str[i] << " " << str[r] << endl;
                if(str[i] == str[r])
                {
                    // cout << "here\n";
                    a=i-l;
                    break;
                }
            }
            for(ll i=r-1; i>l; i--)
            {
                // cout << str[i] << " " << str[r] << endl;
                if(str[i] == str[l])
                {
                    b=r-i;
                    break;
                }
            }
            if(a<b)
            {
                // cout << l << " a " << r << endl;
                counts += a;
                swap(str[l],str[a+l]);
            }
            else
            {
                // cout << l << " b " << r << endl;
                counts += b;
                swap(str[r],str[r-b]);
                // cout << str << endl;
            }
            l++;
            r--;
            cout << str << endl;
        }
    }    
    cout << counts << '\n';
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