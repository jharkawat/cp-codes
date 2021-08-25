#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    string s;
    getline(cin, s);
    int arr[26];
    for(int i=0; i<26; i++)
    {
        arr[i] = 0;
    }
    for(ll i  = 0; i< s.size(); i++)
    {
        // cout << s[i] << endl;
        if(s[i]>='A' && s[i]<='Z')
        {
            // cout << "upper" << endl;
            int pos = s[i]-'A';
            arr[pos]++;
        }
        else if(s[i]>='a' && s[i]<='z')
        {
            // cout << "lower" << endl;
            int pos = s[i]-'a';
            arr[pos]++;
        }
    }
    for(ll i=0; i<26; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// O(n)

signed main()
{
    IOS
    ll t; cin >>t;
    string temp;
    getline(cin, temp);
    while(t--)
    {
        solve();
    }
}