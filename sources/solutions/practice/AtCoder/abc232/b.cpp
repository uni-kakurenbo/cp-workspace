#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string rotate(string s, int k) {
  for(int i=0; i < s.length(); i++) {
    s[i] = 'a'+(s[i]+k-'a')%26;
  }
  return s;
}

int main() {
  string S, T; cin >> S >> T;
  bool ans = false;
  for(int i=0; i< 26; i++)
    if(rotate(S, i) == T) {
      ans = true;
      break;
    }
  cout << (ans?"Yes":"No") << endl;
  return 0;
}
