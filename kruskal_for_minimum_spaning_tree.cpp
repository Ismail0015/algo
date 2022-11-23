#include<bits/stdc++.h>
using namespace std;
const int MX = 1e5+5;
struct edge{
   int a, b, w;
};
edge arr[MX]; int par[MX];
bool cmp(edge a, edge b){
   if(a.w < b.w)return true;
   return false;
}
int find(int a){
   if(par[a] == -1)return a;
   return find(par[a]);
}
void merge(int a, int b){
   par[a] = b;
}
int main(){
   int n, m; cin >> n >> m;
   for(int i = 0; i < m; i++){
      cin >> arr[i].a >> arr[i].b >> arr[i].w;
   }
   int sum = 0;
   for(int i = 1; i <= n; i++)par[i] = -1;
   sort(arr, arr+m, cmp);
   for(int i = 0; i < m; i++){
       int a = find(arr[i].a), b = find(arr[i].b);
         if(a!=b) sum += arr[i].w,
          merge(a,b);
   }cout << sum;
}
