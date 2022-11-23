#include<bits/stdc++.h>
using namespace std;
int main(){
   int n; cin >> n;
     int a[n+1]; for(int i = 0; i < n; i++)cin >> a[i];
     int i = 0, c = 0;vector<int>v;

        for(int i = 0; i <n; i++){
            int x = abs(a[i]);
            if(a[x]<0)v.push_back(x);
            a[x]*=-1;
        }
    for(auto x:v)cout << x << " ";
}
///5
///2 3 2 4 5
