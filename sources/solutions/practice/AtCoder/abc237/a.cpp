#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
  ll N; cin >> N;
  if(-2147483648 <= N && N < 2147483648) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  cout << endl;
}
