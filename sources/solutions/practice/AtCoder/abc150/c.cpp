#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define ALL(I) I.begin(), I.end()

signed main() {
  int n; cin >> n;
  vector<int> V(n), A(n), B(n);
  for(int i=0; i<n; i++) V[i] = i+1;
  for(int& a : A) cin >> a;
  for(int& b : B) cin >> b;
  int a, b;
  int i = 1;
  do {
    if(equal(ALL(A), ALL(V))) a = i;
    if(equal(ALL(B), ALL(V))) b = i;
    i++;
  } while(next_permutation(ALL(V)));
  cout << abs(a-b) << endl;
  return 0;
}
