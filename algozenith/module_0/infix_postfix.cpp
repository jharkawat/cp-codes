#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
conditions
*/


void solve()
{
    // cout << "here 0 \n";
    string str;
    cin >> str;
    string ans = {};
    stack<char> oper;
    map<char,int> precedence;
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;
    precedence['^'] = 3;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^')
        {
            // cout << "here 1 \n";
            if(oper.empty())
            {
                // cout << "here 2 \n";
                oper.push(str[i]);
            }
            else
            {
                // cout << "here 3 \n";
                if(precedence[oper.top()]<precedence[str[i]])
                {
                    // cout << "here 4 \n";
                    oper.push(str[i]);
                }
                else if(precedence[oper.top()]>=precedence[str[i]])
                {
                    cout << oper.top() << endl;

                    while((precedence[oper.top()]<precedence[str[i]]))
                    {
                        if(oper.empty())
                        {
                            break;
                        }
                        ans.push_back(oper.top());
                        oper.pop();
                    }
                    oper.push(str[i]);
                    // cout << "here 6 \n";
                }
                else if(str[i]=='(')
                {
                    oper.push(str[i]);
                }
                // else
                // {
                //     while(oper.top()!='(')
                //     {
                //         cout << "here 7 \n";
                //         ans.push_back(oper.top());
                //         oper.pop();                        
                //     }
                //     cout << "here 8 \n";
                //     oper.pop();
                // }
            }
        }
        else if(str[i]=='(' || str[i]==')')
        {
            if(str[i]=='(')
            {
                oper.push(str[i]);
            }
        }
        else
        {
            ans.push_back(str[i]);
        }
    }
    cout << ans << endl;
}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    
    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}