#include<bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  if(N >= 42) N++;
  cout << "AGC" << setw(3) << setfill('0') << N << endl;

  return 0;
}
