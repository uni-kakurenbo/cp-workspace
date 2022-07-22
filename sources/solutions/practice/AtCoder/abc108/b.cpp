#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)

#define ALL(I) I.begin(), I.end()

signed main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int dx = x1 - x2, dy = y1 - y2;
  cout << x2 + dy << endl;
  cout << y2 - dx << endl;
  cout << x1 + dy << endl;
  cout << y1 - dx << endl;
  return 0;
}
