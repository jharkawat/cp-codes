#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool check(string s)
{
    ll j = s.size();
    for(ll i=0; i<s.size()/2; i++)
    {
        if(s[i] != s[j-i-1])  return false;
    }
    return true;
}


void solve()
{
    string pal; 
    getline(cin, pal);
    for(ll i=0; i<pal.size(); i++)
    {
        if(( pal[i] >= 97) && (pal[i] <= 122))
        {
            continue;
        }
        else
        {
            pal.erase(i,1);
            i--;
        }
    }
    // cout << pal << endl;
    if(check(pal))
    {
        cout << "YES" << "\n";
    }
    else
    {
        cout << "NO" << "\n";        
    }
}

signed main()
{
    IOS
    ll t;
    cin >> t;
    string temp;
    getline(cin,temp);
    while(t--)
    {
        solve();
    }
}