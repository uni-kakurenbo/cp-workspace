#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0;i<ll(n);i++)
string shift(string str, int c) {
  string out = "";
  int length = str.size();
  REP(i, length) {
    out += str[(i + c) % length];
  }
  return out;
}
signed main(){
  string S;
  cin >> S;
  string min = S, max = S;
  REP(n, S.size()) {
    string shifted = shift(S, n);
    if(shifted < min) min = shifted;
    if(shifted > max) max = shifted;
  }
  cout << min << endl << max << endl;;
}
