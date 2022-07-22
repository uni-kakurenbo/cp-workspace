#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)

#define ALL(I) I.begin(), I.end()

signed main() {
  int n; cin >> n;
  int x=0, ans = 0;
  REP(i, n) {
    char s; cin >> s;
    if(s == 'I') x++;
    else x--;
    ans = max(ans, x);
  }
  cout << ans << endl;
  return 0;
}
