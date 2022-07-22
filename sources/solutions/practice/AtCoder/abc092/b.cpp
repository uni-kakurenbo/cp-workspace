#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
  int n, d, x;
  cin >> n >> d >> x;
  vector<int> A(n);
  for(int& a : A) cin >> a;
  int ate=0;
  for(int& a : A)
    for(int j=0; j*a < d; j++) {
      ate++;
    }
  cout << ate + x << endl;
  return 0;
}
