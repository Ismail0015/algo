///Minimum spanning tree
#include<bits/stdc++.h>
using namespace std;
struct edge{
    int a, b, w;
};
edge arr[100000]; int par[100000];
bool cmp(edge a, edge b){
    if(a.w < b.w)return true;
    return false;
}
int find(int a){
    if(par[a] == -1)return a;
    return par[a] = find(par[a]);
}
void merge(int a, int b){
   par[a] = b;
}
int main()
{
    int n, m, a, b, w;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> arr[i].a >> arr[i].b >> arr[i].w;
    }
    for(int i = 1; i <= n ;i++)par[i] = -1;
    sort(arr, arr + m, cmp);
    int sum = 0;
    for(int i = 0; i < m; i++){
        a = find(arr[i].a), b = find(arr[i].b);
        if(a != b)sum += arr[i].w,
        merge(a, b);
    }cout << sum;
}


