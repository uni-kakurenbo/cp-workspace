#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  string s; cin >> s;
  size_t indA = s.find_first_of('A');
  size_t indZ = s.find_last_of('Z');
  cout << indZ - indA + 1 << endl;
  return 0;
}
