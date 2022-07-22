#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)

#define ALL(I) I.begin(), I.end()

signed main() {
  string s; cin >> s;
  int ans = 1000;
  FOR(i, 0, s.length()-3) {
    int x = stoi(s.substr(i, 3));
    ans = min(ans, abs(753-x));
  }
  cout << ans << endl;
  return 0;
}
