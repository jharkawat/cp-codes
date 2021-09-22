#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> g[100100];

int sz[100100];
int indp[100100];
int outdp[100100];

void indfs(int node,int par){
indp[node] = 0;
sz[node] = 1;
for(auto v:g[node]){
if(v!=par){
indfs(v,node); 
sz[node] += sz[v];
indp[node] += indp[v]+sz[v];
}
}
}

void outdfs(int node,int par){
if(node==1){
outdp[node] = 0;
}else{
outdp[node] = outdp[par]+indp[par] - (indp[node]+sz[node]) + (n-sz[node]);
}
for(auto v:g[node]){
if(v!=par){
outdfs(v,node);
}
}
}

void solve(){
cin>>n;
for(int i=0;i<n-1;i++){
int a,b;
cin>>a>>b;
g[a].push_back(b);
g[b].push_back(a);
}
indfs(1,0);
outdfs(1,0);
for(int i=1;i<=n;i++){
cout<<indp[i]+outdp[i]<<" ";
}
} 

signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//int _t;cin>>_t;while(_t--)
solve();
} 