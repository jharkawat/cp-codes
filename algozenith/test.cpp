bool vis[100001];
lli dis[100001];
lli cnt[100100];
graph g;

class prioritize {
public: bool operator ()(ii &p1 , ii &p2) {
return p1.S > p2.S;
}
};

void Dijkstra(int s, int n) {
for (int i = 0; i <= n; i++) {
vis[i] = false;
dis[i] = INT_MAX;
cnt[i] = 0;
}
priority_queue<ii, vector<ii>, prioritize> pq;
pq.push(MP(s, dis[s] = 0));
cnt[s] = 1;
while (!pq.empty()) {
ii cur = pq.top(); pq.pop();
lli cv = cur.F, cw = cur.S;
if (vis[cv]) continue;
vis[cv] = true;
for (ii x : g[cv]) {
if (!vis[x.F] && (cw + x.S) < dis[x.F]) {
pq.push(MP(x.F, dis[x.F] = cw + x.S));
cnt[x.F] = cnt[cv];
}else if((cw + x.S) == dis[x.F]){
cnt[x.F] += cnt[cv];
}
}
}
} 


#include<bits/stdc++.h>
using namespace std;

pair<int,int> dp[1010][1010];
pair<int,int> rec(int i,int j){
if(i>n-1||j>m-1)return make_pair(-1e9,0);
if(i==n-1&&j==m-1){
return make_pair(arr[i][j],1);
}
if(dp[i][j]!=make_pair(-1,-1)){
return dp[i][j];
}
pair<int,int> val1,val2;
val1 = rec(i+1,j);
val2 = rec(i,j+1);
if(val1.first==val2.first){
return dp[i][j] = {arr[i][j] + val1.first, val1.second+val2.second};
}else{
val1 = max(val1,val2);
return dp[i][j] = {arr[i][j] + val1.first, val1.second};
}
}

void solve(){

}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
solve();
} 