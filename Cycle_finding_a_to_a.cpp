/// Cycle Finding for undirected graph
#include<bits/stdc++.h>
using namespace std;
const int MX =1e5+15;
vector<int>v[MX]; int vis[MX], par[MX], s = -1, e = -1;
bool dfs(int node, int p){
   vis[node] = 1;

   for(auto child:v[node]){
        if(child == p)continue;
      if(vis[child]){
        s = child, e = node; return 1;
      }
      par[child] = node;
      if(dfs(child, par[child]))return 1;
   }
   return 0;
}
int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >>a >>b;
        v[a].push_back(b), v[b].push_back(a);
    }
     for(int i = 1; i <= n; i++){
            if(!vis[i] and dfs(i,-1))break;
     }

   if(s==-1)cout << "IMPOSSIBLE" << endl;
   else {
         vector<int>ans;
          int i = e;
          while(i!=s){
            ans.push_back(i); i = par[i];
          }
         ans.push_back(s);
         ans.push_back(e);
         cout << ans.size() << endl;
        for(auto x:ans)cout << x << " ";
   }
}
