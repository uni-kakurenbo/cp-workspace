#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  short N; cin >> N;
  map<string, int> V;
  string ans = "";
  short max=0;
  for(short i=0; i<N; i++) {
    string name; cin >> name;
    if(max < ++V[name]) max = V[name], ans = name;
  }
  cout << ans << endl;
}
