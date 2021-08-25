#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
1≤ T ≤ 10^5
1≤ |S| ≤ 10^5
It is guaranteed that the sum of |S| over all test cases does not exceed 10^6.
*/


void solve()
{
    string str; cin >> str;
    ll n = str.size();
    ll row = 0, col = 0;
    multiset<pair<ll,ll>> north, south, east, west;
    ll visted =0, unvisited = 0;
    for(ll i=0; i<str.size(); i++)
    {
        if(str[i] == 'N')
        {
            cout << str[i] << " " << row << " " << col << " " << visted << " " << unvisited << " \n" ;
            if(north.count(make_pair(row,col)) || south.count(make_pair(row,col+1)))
            {
                visted++;
            }
            else
            {
                unvisited++;
                north.insert(make_pair(row,col));
            }
            col++;
        }
        else if(str[i] == 'S')
        {
            cout << str[i] << " " << row << " " << col << " " << visted << " " << unvisited << " \n" ;
            if(north.count(make_pair(row,col-1)) || south.count(make_pair(row,col)))
            {
                visted++;
            }
            else
            {
                unvisited++;
                south.insert(make_pair(row,col));
            }
            col--;
        }
        else if(str[i] == 'E')
        {
            cout << str[i] << " " << row << " " << col << " " << visted << " " << unvisited << " \n" ;
            if(east.count(make_pair(row,col)) || west.count(make_pair(row,col+1)))
            {
                visted++;
            }
            else
            {
                unvisited++;
                east.insert(make_pair(row,col));
            }
            row++;
        }
        else if(str[i] == 'W')
        {
            cout << str[i] << " " << row << " " << col << " " << visted << " " << unvisited << " \n" ;
            if(east.count(make_pair(row-1,col)) || west.count(make_pair(row,col)))
            {
                visted++;
            }
            else
            {
                unvisited++;
                west.insert(make_pair(row,col));
            }
            row--;
        }
    }
    ll ans = unvisited*5 + visted;
    cout << ans << endl;
}

signed main()
{
    IOS

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}