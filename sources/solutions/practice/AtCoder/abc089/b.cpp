#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  bool flag = false;
  for(int i = 0; i < N; i++) {
    string s; cin >> s;
    if(s == "Y") { flag = true; break;}
  }
  if(flag) cout << "Four";
  else cout << "Three";
  cout << endl;
  // ‚±‚±‚ÉƒvƒƒOƒ‰ƒ€‚ð’Ç‹L
}
