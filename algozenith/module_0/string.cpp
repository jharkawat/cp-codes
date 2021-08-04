#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

struct manipulation{
    string str;

    void insert(string s)
    {
        str = s;
    }
    void print(ll a, ll b)
    {
        string temp = str.substr(a,(b-a+1));
        cout << temp << "\n";
    }
    void reverses(ll a, ll b)
    {
        string temp1, temp2, temp3;
        temp1 = str.substr(0,a);
        temp2 = str.substr(a,(b-a+1));
        temp3 = str.substr(b+1,(str.size()-b-1));
        reverse(temp2.begin(), temp2.end());
        str = temp1+temp2+temp3;
    }
    void replace(ll a, ll b, string rep)
    {
        string temp1, temp2, temp3;
        temp1 = str.substr(0,a);
        temp2 = str.substr(a,(b-a+1));
        temp3 = str.substr(b+1,(str.size()-b-1));
        temp2 = rep;
        str = temp1+temp2+temp3;
    }
    void rotate(ll k)
    {
        string temp1, temp2;
        temp1 = str.substr(str.size()-k,k);
        temp2 = str.substr(0,(str.size()-k));
        str = temp1+temp2;        
    }
};

void solve()
{
    string s,query;
    getline(cin,s);
    manipulation strng;
    strng.insert(s);
    ll q; cin >> q;
    while(q--)
    {
        cin >> query;
        if(query == "print")
        {
            ll a,b;
            cin >> a >> b;
            strng.print(a,b);
        }
        else if(query == "reverse")
        {
            ll a,b;
            cin >> a >> b;
            strng.reverses(a,b);
        }
        else if(query == "replace")
        {
            ll a,b;
            cin >> a >> b;
            string rep;
            cin >> rep;
            strng.replace(a,b,rep);
            
        }
        else if(query == "rotate")
        {
            ll k;
            cin >> k;
            strng.rotate(k);
        }
    }
}

signed main()
{
    IOS
    ll t; cin >>t;
    string temp;
    getline(cin,temp);
    while(t--)
    {
        solve();
    }
}