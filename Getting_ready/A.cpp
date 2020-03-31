#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define rep(i,n) for(i=0;i<(n);i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(),c.end()
#define endl "\n"
typedef pair< ll, ll > lpair;

void solve()
{
	string s;
	cin >> s;

	ll i, idx = -1;
	rep(i,s.length()) if(s[i] == '.') idx = i;

	string temp;
	rep(i,s.length()) if(s[i] != '.') temp += s[i];

	ll num = stoll(temp);
	if(idx == -1)
		cout << 1 << endl;
	else
	{
		ll decimal = s.length() - 1 - idx;

		ll den = 1;

		rep(i,decimal) den *= 10; 
		ll g = __gcd(den, num);
		cout << den / g << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin >> t;
	while(t--) solve();

	return 0;
}