#include<bits/stdc++.h>
using namespace std;

int main() {
  string T = "oxxoxxoxxoxxoxx";
  string S; cin >> S;
  if(T.find(S) == string::npos) cout << "No";
  else cout << "Yes";
  cout << endl;
  return 0;
}
