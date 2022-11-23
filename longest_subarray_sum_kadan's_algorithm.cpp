#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int n; cin >> n;
    int a[n+1];
    for(int i = 0; i < n; i++)cin >> a[i];
    int sum = INT_MIN, mex = 0;
    for(int i = 0; i < n; i++){
        mex += a[i];
        sum = max(sum, mex);
        mex = max(mex, 0);
    }cout << sum;
}
