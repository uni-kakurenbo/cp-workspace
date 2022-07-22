#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define FORA(i,I) for(const auto& i:I)

int main() {
  int N; cin >> N;
  unsigned int ans = 0;
  REP(i, N) {
    unsigned int a; cin >> a;
    if(ans < a) ans = a;
    else break;
  }
  cout << ans << endl;
}
