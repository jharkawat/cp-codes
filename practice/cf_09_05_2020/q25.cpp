#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,k;
	cin>>n>>k;

	ll val = 0;
	for(ll i=0;i<k-1;i++){
		if(n-val - 2<= 0){
			break;
		}
		val+=2;
	}

	if((n -  val) % 2== 0 && (val/2 == (k-1))){
		cout<<"YES"<<endl;
		for(ll i=0;i<val/2;i++){
			cout<<2<<" ";
		}
		cout<<(n-val)<<endl;
		return;
	} 

	ll val2 = 0;
	for(ll i=0;i<k-1;i++){
		if(n-val2-1<=0){
			break;
		}
		val2+=1;
	}

	if((n-val2)%2==1 && (val2==k-1)){
		cout<<"YES"<<endl;
		for(ll i=0;i<val2;i++){
			cout<<1<<" ";
		}
		cout<<(n-val2)<<endl;
		return;
	}

	cout<<"NO"<<endl;


	
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin>>t;

	

	while(t--){
		solve();
	}
}