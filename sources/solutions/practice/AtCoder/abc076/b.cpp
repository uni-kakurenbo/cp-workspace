#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K; cin >> N >> K;
  int now = 1;
  for(int i = 0; i < N; i++) {
    if(now * 2 < now + K) now *= 2;
    else now += K;
  }
  cout << now << endl;
}
