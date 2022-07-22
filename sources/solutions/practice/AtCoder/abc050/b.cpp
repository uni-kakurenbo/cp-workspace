#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int n; cin >> n;
  vector<int> T(n);
  int sum = 0;
  REP(i, n) {
    cin >> T[i];
    sum += T[i];
  }
  int m; cin >> m;
  REP(i, m) {
    int p, x; cin >> p >> x;
    cout << sum-T[--p]+x << endl;
  }

  return 0;
}
