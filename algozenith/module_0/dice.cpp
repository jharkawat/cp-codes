#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    vector<int> dice(6);
    for(int i =0; i<6; i++)
    {
        cin >> dice[i];
    }
    string opr;
    cin >> opr;
    for(ll i=0; i<opr.size(); i++)
    {
        if(opr[i]=='N')
        {
            swap(dice[0],dice[1]);
            swap(dice[1],dice[5]);
            swap(dice[5],dice[4]);
            // for(int i =0; i<6; i++)
            // {
            //     cout << dice[i] << " ";
            // }
            // cout << endl;
        }
        else if(opr[i]=='E')
        {
            swap(dice[0],dice[3]);
            swap(dice[3],dice[5]);
            swap(dice[5],dice[2]);
            // for(int i =0; i<6; i++)
            // {
            //     cout << dice[i] << " ";
            // }
            // cout << endl;
        }
        else if(opr[i]=='S')
        {
            swap(dice[0],dice[4]);
            swap(dice[4],dice[5]);
            swap(dice[5],dice[1]);
            // for(int i =0; i<6; i++)
            // {
            //     cout << dice[i] << " ";
            // }
            // cout << endl;
        }
        else if(opr[i]=='W')
        {
            swap(dice[0],dice[2]);
            swap(dice[2],dice[5]);
            swap(dice[5],dice[3]);
            // for(int i =0; i<6; i++)
            // {
            //     cout << dice[i] << " ";
            // }
            // cout << endl;        
        }
        
    }
    cout << dice[0] << endl;
}


signed main()
{
    IOS
    ll t; cin >> t;
    while(t--)
    {
        solve();
    }
}