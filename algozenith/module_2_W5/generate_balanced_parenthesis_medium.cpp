#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

string ans = "";

void dfs(int curLen, int totalLen, int openCnt, int depth, int k) {
    if(curLen == totalLen) {
        assert(openCnt == 1);
        ans += ")";
        if(depth == k) cout << ans << "\n";
        ans.pop_back();
        return;
    }

    if(!openCnt) {
        ans += "(";
        dfs(curLen + 1, totalLen, openCnt + 1, max(depth, openCnt + 1), k);
        ans.pop_back();
    }
    else {
        int remLen = totalLen - curLen + 1;
        if(remLen > openCnt && openCnt < k) {
            ans += "(";
            dfs(curLen + 1, totalLen, openCnt + 1, max(depth, openCnt + 1), k);
            ans.pop_back();
        }
        ans += ")";
        dfs(curLen + 1, totalLen, openCnt - 1, max(depth, openCnt - 1), k);
        ans.pop_back();
    }
}

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    dfs(1, n, 0, 0, k);

    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long;

// #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// /*
// conditions
// */
// ll n;
// ll depth = 0;
// ll order;
// string ans = {};

// void solve(int level, int depth)
// {

//     if((level == n))
//     {
//         if((depth == 0))
//         {
//             ll count =0;
//             ll total =0;
//             // cout << ans << endl;
//             for(int i=0; i<n; i++)
//             {
//                 if(ans[i] == '(')
//                 {
//                     count++;
//                     total = max(total,count);
//                     // cout << total << " " << count << endl;
//                 }
//                 else
//                 {
//                     count--;
//                 }
//             }
//             if(total == order)
//             {
//                 cout << ans << "\n";
//             }
//         } 
//         return;
//     }
//     else
//     {
//         ans += "(";
//         // cout << "here" << endl;
//         solve(level+1,depth+1);
//         ans.pop_back();
//         if(depth) {
//             ans += ")";
//             solve(level+1,depth-1);
//             ans.pop_back();
//         }
//     }
// }

// signed main()
// {
//     IOS

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif

//     cin >> n >> order;
//     solve(0,0);
// }