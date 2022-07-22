#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define FORA(i,I) for(const auto& i:I)

#define ALL(x) x.begin(),x.end() 
#define SIZE(x) ll(x.size()) 

#define INF32 2147483647
#define INF64 9223372036854775807
#define MOD 1000000007

#define F first
#define S second

#define coutALL(x) for(auto i=x.begin();i!=--x.end();i++)cout<<*i<<" ";cout<<*--x.end()<<endl;

ll myceil(ll a,ll b){return (a+(b-1))/b;}
ll myfloor(ll a,ll b){return a/b;}

signed main(){
  	map<int, int> x, y;
  	REP(i, 3) {
      int a, b; cin >> a >> b;
      x[a]++; y[b]++;
    }
  	for(auto [k, v] : x) {
      if(v == 1) cout << k << " ";
    }
  	for(auto [k, v] : y) {
      if(v == 1) cout << k << endl;
    }
    return 0;
}
