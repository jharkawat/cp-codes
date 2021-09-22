#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,u;
    cin>>n>>u;

    int arr[n];
    vector<int> activate[n];
    vector<int> deactivate[n];

    for(int i=0;i<u;i++){
        int l,r,x;
        cin>>l>>r>>x;
        activate[l].push_back(x);
        deactivate[r].push_back(x);
    }

    multiset<int> mt;
    for(int i=0;i<n;i++){
        for(auto v:activate[i]){
            mt.insert(v);
        }
        if(mt.empty()){
            arr[i]=0;
        }
        else{
            arr[i] = *mt.rbegin();
        }
        cout<<arr[i]<<" ";
        for(auto v:deactivate[i]){
            mt.erase(mt.find(v));
        }
    }


}    

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int _t;cin>>_t;while(_t--)
    solve();
}
