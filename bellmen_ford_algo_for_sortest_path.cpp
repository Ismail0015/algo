#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
int main()
{
   int n, m;
   cin >> n >> m;
   vector<vector<int>>v;
   for(int i = 0; i < m; i++){
      int a, b, w;
      cin >> a >> b >> w;
      v.push_back({a, b, w});
   }
   int src; cin >> src;
   vector<int>dis(n,INF);
   dis[src] = 0;
   for(int i = 0; i < n-1; i++){
     for(auto x : v){
     int a = x[0], b= x[1], w = x[2];
     dis[b] = min(dis[b], w + dis[a]);
     }
   }
  cout << dis[n];
}

