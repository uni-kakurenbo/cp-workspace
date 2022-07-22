#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)

int main() {
  int N; cin >> N;
  vector<int> C(N, 0);
  REP(i, N*4-1) {
    int a; cin >> a;
    C[a-1]++;
  }
  auto iter = min_element(C.begin(), C.end());
  int index = distance(C.begin(), iter);
  cout << index+1 << endl;
}
