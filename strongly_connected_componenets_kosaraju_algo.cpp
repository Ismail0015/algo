#include<bits/stdc++.h>
using namespace std;
const int MX = 10e5;
vector<int>v[MX], vr[MX],tmp,ans; int vis[MX];
void dfs(int x){
   vis[x] = 1;
   for(auto i:v[x]){
    if(!vis[i])dfs(i);
   }
   tmp.push_back(x);
}
void dfs1(int x){
   vis[x] = 1;
   for(auto i:vr[x]){
    if(!vis[i])dfs1(i);
   }
   ans.push_back(x);
}
int main(){
  int n, m, k; cin >> n >> m >> k;
  for(int i = 0; i < n; i++){
     int a, b; cin >> a >> b;
     v[a].push_back(b);
     vr[b].push_back(a);
  }
  for(int i = 1; i <=m; i++)if(!vis[i])dfs(i);
  for(int i = 1; i <= m; i++)vis[i] = 0;
  for(int i = 1; i <= m; i++){
    if(!vis[tmp[n-i]]){
        ans.clear();
        dfs1(tmp[n-i]);
        for(auto x:ans)cout << x << " "; cout << endl;
    }
  }
}

