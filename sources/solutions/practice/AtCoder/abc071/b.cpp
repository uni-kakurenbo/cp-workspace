#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)

#define ALL(I) I.begin(), I.end()

signed main() {
  string S; cin >> S;
  string A("abcdefghijklmnopqrstuvwxyz");

  for(char& s : S) {
    auto f = find(ALL(A), s);
    if(f != A.end()) A.erase(f);
  }
  if(A.size()) {
    cout << A[0];
  } else {
    cout << "None";
  }
  cout << endl;
  return 0;
}
