#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  short N; cin >> N;
  vector<pair<short, short>> P(N);
  for(short i=0; i<N; i++) {
    short x, y; cin >> x >> y;
    P[i] = pair<short, short> (x, y);
  }
  double max = 0;
  for(short i=0; i<N-1; i++) {
    for(short j=i; j<N; j++) {
      short x1, y1, x2, y2;
      short dx, dy;
      x1 = P[i].first; y1 = P[i].second;
      x2 = P[j].first; y2 = P[j].second;
      dx = abs(x1-x2); dy = abs(y1-y2);
      double dist = sqrt(double(dx*dx + dy*dy));
      if(max < dist) max = dist;
    }
  }
  cout << setprecision(16) << max << endl;
  return 0;
}
