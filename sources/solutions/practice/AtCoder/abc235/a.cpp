#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string abc; cin >> abc;
  string bca = {abc[1], abc[2], abc[0]};
  string cab = {abc[2], abc[0], abc[1]};
  cout << atoi(abc.c_str()) + atoi(bca.c_str()) + atoi(cab.c_str()) << endl;
  return 0;
}
