#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)

#define ALL(I) I.begin(), I.end()

signed main() {
  int a, b; cin >> a >> b;
  string s; cin >> s;
  bool ans = true;
  if(s[a] != '-') ans = false;
  if(ans) {
    REP(i, s.length()) {
      if(i == a) continue;
      if(s[i] < '0' || '9' < s[i]) ans = false;
    }
  }
  cout << (ans?"Yes":"No") << endl;
  return 0;
}
