#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(int t) {
  return t*t + 2*t + 3;
}

int main() {
  int t; cin >> t;
  cout << f(f(f(t)+t)+f(f(t))) << endl;
  return 0;
}
