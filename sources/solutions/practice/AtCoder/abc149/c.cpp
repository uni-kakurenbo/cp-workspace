#include<bits/stdc++.h>
using namespace std;

signed main() {
  int x; cin >> x;
  int m = x*2;
  
  vector<bool> prime(m+10, true);
  for(int p=2;p*p<=m;p++)if(prime[p])for(int i=p*p;i<=m;i+=p)prime[i]=false;
  
  int i=x;
  while(i < m) {
    if(prime[i]) break;
    i++;
  }
  cout << i << endl;
  return 0;
}
