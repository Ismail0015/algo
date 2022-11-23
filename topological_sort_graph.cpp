#include<bits/stdc++.h>
using namespace std;
const int MX = 2e5+5;
vector<int>v[MX], ans; int vis[MX], vis1[MX];
void dfs(int x){
     vis[x] = 1;
     for(auto i:v[x]){
        if(!vis[i])dfs(i);
     }
     ans.push_back(x);
}
bool cycle(int x){
   vis1[x] = 1;
   for(auto i:v[x]){
     if(!vis1[i]){
            if(cycle(i))return 1;
     }
     else if(vis1[i] == 1)return 1;
   }
   vis1[x] = 2;
   return 0;
}
int main(){
   int n, m;
   cin >> n >> m;

   for(int i = 0;i  < m; i++){
     int a, b;
     cin >> a >> b;
     v[a].push_back(b);
   } bool f = false;
   for(int i = 1; i <= n; i++){
    if(!vis1[i] and cycle(i))f = true;
     if(!vis[i]){
         dfs(i);
     }
   }
   reverse(ans.begin(), ans.end());
   if(f)cout << "IMPOSSIBLE";
   else
   for(auto x:ans)cout << x << " ";
}
