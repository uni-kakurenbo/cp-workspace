#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B;
  cin >> A >> B;
  int ans = 0;
  for(int i = A; i <= B; i++) {
    string N = "";
    N[0] = (i / 10000)% 10;
    N[1] = (i / 1000)% 10;
    N[2] = (i / 100)% 10;
    N[3] = (i / 10)% 10;
    N[4] = i % 10;
    if(N[0] == N[4] && N[1] == N[3]) {
      ans++;
    }
  }
  cout << ans << endl;
}
