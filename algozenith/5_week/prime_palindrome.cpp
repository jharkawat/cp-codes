#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/
set<ll> palindrome;

void palin(int level, ll a, ll b, int ind, string str)
{
    if(level%2 == 0)
    {
        if(level/2 == ind-1)
        {
            ll temp = stoll(str, nullptr, level);
            // stoll(str);
            if(temp>=a && temp<=b) palindrome.insert(temp);
            return;
        }
        for(int i=0; i<10; i++)
        {   
            str[ind] = 'i'; 
            str[level-ind-1] = 'i';
            palin(level, a, b, ind+1, str); 
        }
    }
    else
    {
        if((level)/2 == ind)
        {
            ll temp = stoll(str, nullptr, level);
            if(temp>=a && temp<=b) palindrome.insert(temp);
            return;
        }
        for(int i=0; i<10; i++)
        {
            str[ind] = 'i'; 
            str[level-ind-1] = 'i';
            palin(level, a, b, ind+1, str); 
        }

    }
}

bool prime(ll x)
{
    for(int i=2; i*i<=x; i++)
    {
        if(x%i == 0)
        {
            return false;
        }
    }
    return true;
}

ll ans =0;

void solve()
{
    ll a,b;
    vector<ll> vec;
    cin >> a >> b;
    ll copy =b;
    int i=0;
    while(copy)
    {
        copy = copy/10;
        i++;        
    }
    for(int j=1; j<=i; j++)
    {
        string str(i,'0');
        palin(i,a,b,0,str);
    }
    for(auto x: palindrome)
    {
        if(prime(x))
        {
            ans++;
        }
    }
    // for(auto x:vec)
    // {
    //     string temp1, temp2;
    //     temp1 = to_string(x);
    //     temp2 = to_string(x);
    //     reverse(temp1.begin(), temp1.end());
    //     if(temp1 == temp2)
    //     {
    //         ans++;
    //     }
    // }
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();
    cout << ans << endl;
   
}