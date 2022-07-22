#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int ans = 0;
  for(int i = 0; i < N; i++) {
    int l, r;
    cin >> l >> r;
    ans += r - l + 1;
  }
  cout << ans << endl;
}
