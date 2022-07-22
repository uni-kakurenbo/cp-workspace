#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)

int main(){
  string s; cin >> s;
  int ans = 1;
  for(char& c : s) {
    switch(c) {
      case '+': ans += 1; break;
      case '-': ans -= 1; break;
    }
  }
  cout << ans << endl;
  return 0;
}
