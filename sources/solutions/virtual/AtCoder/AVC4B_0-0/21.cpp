#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  string s; cin >> s;
  ll k; cin >> k; k--;

  int i=0;
  while(s[i] == '1') i++;

  if(k >= i) cout << s[i];
  else cout << 1;
  cout << "\n";

  return 0;
}
