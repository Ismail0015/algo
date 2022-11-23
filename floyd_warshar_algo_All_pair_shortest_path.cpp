#include<bits/stdc++.h>
#define int long long
using namespace std;
int dis[505][505]; const int MX = 1e12;
int32_t main(){
   int n, m, q;
   cin >> n >> m >> q;

   for(int i = 1; i <= n+1; i++){
     for(int j = 1; j <= n+1;j++)dis[i][j] = MX;
   }
   for(int i = 1; i <= m; i++){
      int a, b, w; cin >> a >> b >> w;
      dis[a][a] = 0, dis[b][b] = 0;
      dis[a][b] = min(dis[a][b], w), dis[b][a] = min(dis[b][a], w);
   }
   for(int k = 1; k <= n+1; k++){
     for(int i = 1; i <= n+1; i++){
        for(int j = 1; j <= n+1; j++){
            dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
        }
     }
   }
   for(int i = 0; i < q; i++){
      int a, b; cin >> a >> b;
      if(dis[a][b] == MX)cout << -1 << endl;
      else cout << dis[a][b] << endl;
   }
}
