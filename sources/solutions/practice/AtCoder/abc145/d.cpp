#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

const int MOD = 1e9 + 7;
vector<long long> fact_inv, inv, Com;

void init_nCk(int n, int SIZE) {
    fact_inv.resize(SIZE + 5);
    inv.resize(SIZE + 5);
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < SIZE + 5; i++) {
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
    Com.resize(SIZE + 5);
    Com[0] = 1;
    for (int i = 1; i < SIZE + 5; i++) {
        Com[i] = Com[i - 1] * ((n - i + 1) * inv[i] % MOD) % MOD;
    }
}

ll nCk(int k) {
    return Com[k];
}

signed main() {
  int x, y; cin >> x >> y;
  
  if((x+y)%3 != 0) { cout << 0 << endl; return 0; }
  if(y > 2*x || 2*y < x) { cout << 0 << endl; return 0; }
  
  init_nCk((x+y)/3, (x+y)/3);
  
  //cerr << (x+y)/3 << "," << (2*y-x)/3 << endl;
  cout << nCk((2*y-x)/3) << endl;
  
  return 0;
}
