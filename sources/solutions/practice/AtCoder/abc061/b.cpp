#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int n, m; cin >> n >> m;
  vector<int> T(n, 0);
  REP(i, m) {
    int a, b; cin >> a >> b;
    a--; b--;
    T[a]++; T[b]++;
  }
  REP(i, n) cout << T[i] << endl;
  return 0;
}
