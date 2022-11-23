#include<bits/stdc++.h>
using namespace std;
const int MX = 2e5+5;
vector<int>v[MX], ans; int vis1[MX];
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
     v[b].push_back(a);
   }
   bool f = false;
   for(int i = 1; i <= n; i++){
    if(!vis1[i] and cycle(i))f = true;
   }
  if(f)cout << "YES";

}

