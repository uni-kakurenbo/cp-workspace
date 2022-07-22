#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, a, b; cin >> n >> a >> b;
  string S; cin >> S;
  ll sum = 0, sum_b = 0;
  for(char& s : S) {
    if(
      s == 'b' && ++sum_b <= b && sum < a+b ||
      s == 'a' && sum < a+b
    ) {
      sum++;
      cout << "Yes";
    } else cout << "No";
    cout << endl;
  }
}
