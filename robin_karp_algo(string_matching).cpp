#include <bits/stdc++.h>
using namespace std;
vector<int>fun(string s){
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
int main()
{
  string t, s; cin >> t >> s;
  t = s+'#'+t;cout << t;
  vector<int>v = fun(t);
  int ans = 0;
  for(auto x:v)if(x == s.size())ans++;
  cout << ans;
}
