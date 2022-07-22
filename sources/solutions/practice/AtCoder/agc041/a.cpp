#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  ll n, a, b; cin >> n >> a >> b;
  ll ans = 0;
  auto calc = [](ll i, ll j) {
    return (j-i)/2;
  };
  if(a%2 == b%2) {
    ans = calc(a, b);
  } else {
    ans = min(a-1, n-b)+calc(a+1, b)+1;
  }
  cout << ans << endl;
  return 0;
}

