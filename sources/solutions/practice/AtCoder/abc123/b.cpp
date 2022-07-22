#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(const auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int sum=0;
  int min_sp = 20;
  REP(i, 5) {
    int x; cin >> x;
    sum += ((x+9)/10)*10;
    min_sp = min(min_sp, x - ((x+9)/10)*10);
  }
  sum += min_sp;
  cout << sum << endl;
  return 0;
}
