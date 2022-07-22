#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  ll n; cin >> n;
  int d = log10(n)+1;
  string x;
  REP(i, d) x += '9';
  int i = 0;
  ll k = stoll(x);
  while(k > n) {
    if(x[i] == '0') i++;
    x[i] -= 1;
    k = stoll(x);
  }
  int ans = 0;
  while(k) ans+=k%10, k/=10;
  cout << ans << endl;
  return 0;
}
