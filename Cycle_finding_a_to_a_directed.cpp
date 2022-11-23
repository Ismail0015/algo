/// Cycle Finding for directed graph
#include<bits/stdc++.h>
using namespace std;
const int MX =1e5+15;
vector<int>v[MX]; int vis[MX], par[MX], s = -1, e = -1;
bool dfs(int node){
   vis[node] = 1;

   for(auto child:v[node]){
        if(!vis[child]){
            par[child] = node;
            if(dfs(child))return 1;
        }
        else if(vis[child] == 1){
            s = child, e = node; return 1;
        }
   }vis[node] = 2;
   return 0;
}
int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >>a >>b;
        v[a].push_back(b);
    }
     for(int i = 1; i <= n; i++){
            if(!vis[i] and dfs(i))break;
     }

   if(s==-1)cout << "IMPOSSIBLE" << endl;
   else {
         vector<int>ans;
         ans.push_back(s);
         for(int i = e; i != s; i = par[i]){
            ans.push_back(i);
         }
         ans.push_back(s);
         reverse(ans.begin(), ans.end());
         cout << ans.size() << endl;
        for(auto x:ans)cout << x << " ";
   }
}

