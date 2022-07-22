#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K; cin >> N >> K;
  int ans = 0;
  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    if(x < K - x) ans += x;
    else ans += (K - x);
  }
  cout << ans * 2 << endl;
}
