#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
    1≤ T ≤ 2*10^5
    1≤ |S| ≤ 10^5
    It is guaranteed that the sum  of |S| over all test cases does not exceed 106.
*/


void solve()
{
    string str;
    cin >> str;
    map<char,int> paran;
    paran['('] = 1;
    paran['{'] = 2;
    paran['['] = 3;
    paran[')'] = 4;
    paran['}'] = 5;
    paran[']'] = 6;
    ll ans = 0;
    stack<int> st; 
    for(auto s: str)
    {
        // cout << paran[s] << endl;

        if(paran[s]>3)
        {
            if(!st.empty() && (paran[s]-3)==st.top() )
            {
                st.pop();
                ans--;
                // cout << ans << " " << s << " 1" << endl;
            } 
            else if(!st.empty() && (paran[s]-3)!=st.top())
            {
                ans++;
                // cout << ans << " " << s << " 2" << endl;            
            }
            else
            {
                ans++;
            }
        }
        else
        {
            st.push(paran[s]);
            ans++;
            // cout << ans << " " << s << " 3" << endl;
        }
    }
    cout << ans << endl;

}

signed main()
{
    IOS

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ll t; cin >> t; 
    while(t--)
    {
        solve();
    }
}