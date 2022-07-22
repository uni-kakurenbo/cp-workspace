#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  string s, t; cin >> s >> t;
  sort(ALL(s));
  sort(ALL(t)); reverse(ALL(t));
  cout << (s<t?"Yes":"No") << endl;
}
