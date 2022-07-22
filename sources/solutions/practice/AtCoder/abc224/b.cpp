#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)

signed main(){
  int H, W;
  cin >> H >> W;
  vector<vector<ll>> A(H, vector<ll>(W));
  
  REP(i, H) {
    REP(j, W) {
      cin >> A[i][j];
    }
  }
  
  bool flag = true;
  REP(i2, H) {
   	REP(i1, i2) {
      REP(j2, W) {
        REP(j1, j2) {
         //cout << i1 << "," << i2 << "," << j1 << "," << j2 << endl;
      	 if(A[i1][j1] + A[i2][j2] > A[i2][j1] + A[i1][j2]) {
       	    flag = false;
       	    break;
          }
        }
        if(!flag) break;
      }
      if(!flag) break;
    }
    if(!flag) break;
  }
  
  if(flag) cout << "Yes";
  else cout << "No";
  cout << endl;
}
