#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N; cin >> N;
  int f;
  for(int i = N; i > 0; i /= 10) f += i % 10;
  //cout << f << endl;
  if(N % f == 0) cout << "Yes";
  else cout << "No";
  cout << endl;
}
