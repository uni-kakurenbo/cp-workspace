#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

using Graph = vector<vector<int>>;
signed main() {
  int n, m; cin >> n >> m;
  
  Graph G(n);
  REP(i, m) {
    int a, b; cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  vector<int> dist(n, -1);
  queue<int> que;

  dist[0] = 0;
  que.push(0);

  while (!que.empty()) {
   int v = que.front();
   que.pop();

    for (int nv : G[v]) {
      if (dist[nv] != -1) continue;
      dist[nv] = dist[v] + 1;
      que.push(nv);
    }
  }

  cout << (dist[n-1]==2?"POSSIBLE":"IMPOSSIBLE") << endl;
  
  return 0;
}
