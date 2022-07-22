#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  string s; cin >> s;
  bool ans = s[0] == 'A';
  string t = s.substr(2, s.size()-3);
  ans &= count(ALL(t), 'C') == 1;
  FOR(i, 1, s.size()-1) {
    ans &= ('a' <= s[i] && s[i] <= 'z') || (s[i] == 'C' && 2 <= i && i <= s.size()- 2);
  }
  cout << (ans?"AC":"WA") << endl;
  return 0;
}
