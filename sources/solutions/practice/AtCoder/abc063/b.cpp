#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)

#define ALL(I) I.begin(), I.end()

signed main() {
  string s; cin >> s;
  map<char, int> mp;
  for(char& i : s) {
    if(mp[i]) {
      cout << "no" << endl;
      exit(0);
    }
    mp[i]++;
  }
  cout << "yes" << endl;
  return 0;
}
