#include<bits/stdc++.h>
#define INF 1e18
using namespace std;
const int MX = 1e5+5;
vector<int>v[MX]; int dis[MX], p[MX];
void dfs(int x){
   if(x != 1)dfs(p[x]);
   cout << x << " ";
}
int main(){
   int n, m;
   cin >> n >> m;
   map<pair<int, int>, int>mp;
   for(int i = 0; i < m; i++){
      int a, b, w; cin >> a >> b >> w;
      v[a].push_back(b);
      v[b].push_back(a); mp[{a,b}] = w, mp[{b,a}] = w;
   }
   for(int i = 2; i <= n; i++)dis[i] = INF;
   priority_queue<int>q;
   q.push(1);
   while(!q.empty()){
      int x = q.top();
      q.pop();
      for(auto i: v[x]){
          int w = mp[{x,i}];
          if(dis[x]+w < dis[i])dis[i] = dis[x] + w, q.push(i), p[i] = x;
      }
   }
   dfs(n);
   //cout << dis[n];
}
