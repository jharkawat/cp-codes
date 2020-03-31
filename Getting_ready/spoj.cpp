#include <bits/stdc++.h>
#define ll long long int 

using namespace std;

int main(){

	ll t;
	cin>>t;

	while(t--){
		
		double num;
		cin>>num;

		ll numerator = num*10000;
		ll denominator = 10000;

		ll nm=numerator, dn = denominator;

		while(__gcd(nm, dn) != 1){

			ll gg = __gcd(nm, dn);
			nm/=gg;
			dn/=gg;
		}

		cout<<dn<<endl;
	}	
}