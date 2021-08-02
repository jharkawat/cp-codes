#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mo =1000000007;

long long pows(ll base, ll exp)
{
    if(exp == 1) 
    {
        return base%mo;
    }
    else if(exp%2 == 0)
    {
        ll ans = pows(base,exp/2)%mo;
        return (ans*ans)%mo;
    }
    else
    {
        ll ans = pows(base,exp/2)%mo;
        return (ans*ans*base)%mo;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll ans = (pows(26,n)-pows(5,n)-pows(21,n))%mo;
        cout << ans << endl;
    }
}