#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
  int n, x; cin >> n >> x;
  vector<ll> A(n);
  ll sum = 0;
  for(ll& a : A) {
    cin >> a;
    sum += a;
  }
  sort(A.begin(), A.end());
  
  int i = 0;
  ll now = 0;
  while(i < n && now <= x) {
    now += A[i];
    i++;
  }
  if(sum != x) i--;
  cout << i << endl;
}
