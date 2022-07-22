#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

using Town = pair<int, int>;
double dist(Town a, Town b) {
  int dx = a.first-b.first;
  int dy = a.second-b.second;
  return sqrt(dx*dx+dy*dy);
}

signed main() {
  int n; cin >> n;
  vector<Town> towns(n);
  FORA(town, towns) {
    int x, y; cin >> x >> y;
    town = Town(x, y);
  }
  vector<int> plan(n);
  iota(ALL(plan), 0);
  double sum = 0;
  int cnt = 0;
  do {
    double dist_sum = 0;
    int prev_t = plan[0];
    REP(i, n-1) {
      int t = plan[i+1];
      dist_sum += dist(towns[t], towns[prev_t]);
      prev_t = t;
    }
    sum += dist_sum;
    cnt++;
  } while(next_permutation(ALL(plan)));
  printf("%.10f", sum/cnt);
}
