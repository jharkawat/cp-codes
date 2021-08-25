#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve(ll num)
{
    string str;
    cin >> str;
    string copy = str;
    sort(copy.begin(),copy.end());
    bool check = true;
    for(ll i=0; i<str.size(); i++)
    {
        if(str[i]==copy[i])
        {
            check = false;
            break;
        }
    }
    if(check)
    {
        cout<< "Case #" << num << ": " << copy << "\n";
        return;
    }
    while(next_permutation(copy.begin(),copy.end()))
    {
        // cout << copy << endl;
        bool check = true;
        for(ll i=0; i<str.size(); i++)
        {
            if(str[i]==copy[i])
            {
                check = false;
                break;
            }
        }
        if(check)
        {
            cout<< "Case #" << num << ": " << copy << "\n";
            return;
        }
    }
    cout<< "Case #" << num << ": IMPOSSIBLE";



    // map<char,ll> mp;
    // for(ll i=0; i<str.size(); i++)
    // {
    //     mp[str[i]]++;
    // }
    // set<pair<ll,char>> st;
    // for(auto v:mp)
    // {
    //     st.insert({v.second,v.first});
    // }
    // // for(auto v:st)
    // // {
    // //     cout << v.first << " " << v.second << endl;
    // // }
    // if(st.rbegin()->first>str.size()/2)
    // {
    //     cout << "IMPOSSIBLE \n"; 
    //     return;
    // }
    // else
    // {
    // }

}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    
    ll t; cin >> t; 
    for(int i=1; i<=t; i++)
    {
        solve(i);
    }
}