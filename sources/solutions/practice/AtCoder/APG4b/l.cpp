#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A;
  cin >> N >> A;
  for(int i = 0; i < N; i++) {
    string op; int B;
    cin >> op >> B;
    if(op == "/" && B == 0) { cout << "error" << endl; break; }
    cout << (i + 1) << ":";
    if(op == "+") cout << (A += B);
    if(op == "-") cout << (A -= B);
    if(op == "*") cout << (A *= B);
    if(op == "/") cout << (A /= B);
  cout << endl;
  }
  // ‚±‚±‚ÉƒvƒƒOƒ‰ƒ€‚ð’Ç‹L
}
