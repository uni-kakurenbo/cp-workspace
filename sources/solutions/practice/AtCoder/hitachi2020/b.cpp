#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define ALL(I) I.begin(), I.end()

signed main() {
  int a, b, m;
  cin >> a >> b >> m;
  vector<int> A(a), B(b);
  for(int& a : A) cin >> a;
  for(int& b : B) cin >> b;
  int min_cost = *min_element(ALL(A))+*min_element(ALL(B));
  for(int i=0; i<m; i++) {
    int x, y, c; cin >> x >> y >> c;
    x--; y--;
    int cost = A[x] + B[y] - c;
    min_cost = min(min_cost, cost);
  }
  cout << min_cost << endl;
  return 0;
}
