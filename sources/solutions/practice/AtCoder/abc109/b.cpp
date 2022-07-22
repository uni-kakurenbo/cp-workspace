#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int n; cin >> n;
  map<string, int> W;
  string prev;
  cin >> prev;
  bool ans = true;
  REP(i, n-1) {
    W[prev]++;
    string word; cin >> word;
    if(word[0] != prev[prev.size()-1]) {
      ans = false;
      break;
    }
    if(W[word]) {
      ans = false;
      break;
    }
    prev = word;
  }
  cout << (ans?"Yes":"No") << endl;
  return 0;
}
