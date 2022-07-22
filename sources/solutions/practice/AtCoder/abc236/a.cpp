#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string S; cin >> S;
  int a, b; cin >> a >> b;
  char temp = S[a-1];
  S[a-1] = S[b-1];
  S[b-1] = temp;
  cout << S << endl;
}
