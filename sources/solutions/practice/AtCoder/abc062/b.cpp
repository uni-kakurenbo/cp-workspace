#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int h, w; cin >> h >> w;
  REP(i, w+2) cout << '#';
  cout << endl;
  REP(i, h) {
    cout << '#';
    string s; cin >> s;
    cout << s;
    cout << '#' << endl;
  }
  REP(i, w+2) cout << '#';
  cout << endl;
  return 0;
}
