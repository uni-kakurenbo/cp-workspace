#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
  string s; cin >> s;
  auto isACGTChar = [](char& s) {
    return s == 'A' ||s == 'C' ||s == 'G' ||s == 'T';
  };
  int con = 0;
  int ans = 0;
  for(size_t i=0; i<s.length(); i++) {
    if(isACGTChar(s[i])) {
      con++;
      ans = max(ans, con);
    } else {
      con=0;
    }
  }
  cout << ans << endl;
  return 0;
}
