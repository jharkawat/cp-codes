

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
         int q, x;
        cin >> q >> x;
        vector<int> v[x];
        set<int> s;
        for (int i = 0; i <= q; ++i) {
            s.insert(i);
        }
        while (q--) {
            int t;
            cin >> t;
            t%=x;
            if (v[t].empty()) {
                v[t].push_back(t);
            }
            else {
                int xx=v[t].back();
                // cout << xx << endl;
                v[t].push_back(xx+x);
                t=xx+x;
            }
            s.erase(t);
     
            cout << *s.begin() << " ";
        }
        cout << "\n";
    }
    return 0;
}