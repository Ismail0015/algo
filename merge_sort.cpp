#include<bits/stdc++.h>
using namespace std;
int ans = 0;
void merge(int l, int m, int r, int a[], int n){
   int i = l, j = m + 1, k = l;
   int temp[n+1];
   //if(a[i] < a[j]){ ans++;}
   while(i <= m and j <= r){
     if(a[i] <= a[j]){
        temp[k] = a[i]; i++, k++;
     }
     else {
        temp[k] = a[j];
        j++, k++;
     }
   }

   while(i <= m){
      temp[k] = a[i]; i++, k++;
   }
   while(j <= r){
      temp[k] = a[j]; j++, k++;
   }
   for(int p = l; p <= r; p++)a[p] = temp[p];
}
void merge_sort(int l, int r, int a[], int n){
   if(l < r){
   int mid = (l+r)/2;
   merge_sort(l, mid, a, n);
   merge_sort(mid+1, r, a, n);
   merge(l, mid, r, a, n);
   }
}
int main(){
    int t;
    for(cin >> t ;t--;){ans = 0;
    int n; cin >> n; int a[n+1];
    for(int i = 0; i < n; i++)cin >> a[i];

    merge_sort(0, n-1, a, n);
    for(int i = 0; i < n; i++)cout << a[i] << " ";
    }
}
