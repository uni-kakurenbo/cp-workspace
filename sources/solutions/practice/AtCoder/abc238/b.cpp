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
  ll N; cin >> N;
  vector<int> C(N);
  ll sum = 0;
  REP(i, N) {
    ll a; cin >> a;
    ll place = sum + a;
    C[i] = place;
    if(place > 360) C[i] = place % 360;
    sum += a;
  }
  C.push_back(0);
  C.push_back(360);
  sort(ALL(C));
  ll max = 0;
  REP(i, C.size() - 1) {
    ll diff = C[i+1]-C[i];
    if(diff > max) max = diff;
  }
  cout << max << endl;
  return 0;
}
