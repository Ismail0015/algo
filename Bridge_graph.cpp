#include<bits/stdc++.h>
using namespace std;
const int MX = 1e5+5;
vector<int>v[MX]; int in[MX], low[MX], timer, vis[MX];
void dfs(int node, int par){
    in[node] = low[node] = timer;
    timer++;
    vis[node] = 1;
    for(auto child:v[node]){
        if(child == par)continue;

        if(vis[child]){
            low[node] = min(low[node], in[child]);
        }
        else {
            dfs(child, node);
            if(low[child] > in[node])cout << node << "->" << child << endl;
            low[node] = min(low[child], low[node]);
        }
    }
}
int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,-1);
}
