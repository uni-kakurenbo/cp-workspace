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
#define MOD 1000000007 //問題による

#define F first
#define S second

#define coutALL(x) for(auto i=x.begin();i!=--x.end();i++)cout<<*i<<" ";cout<<*--x.end()<<endl;

ll myceil(ll a,ll b){return (a+(b-1))/b;}
ll myfloor(ll a,ll b){return a/b;}

int main(){
  string s, t;
  cin >> s >> t;
  string ans = "No";
  if(s == t) ans = "Yes";
  REP(i, s.size() - 1) {
  	swap(s[i], s[i+1]);
    if(s == t) ans = "Yes";
    swap(s[i], s[i+1]);
  }
  cout << ans << endl;
  //小数の桁数の出力指定
  //cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  //ios::sync_with_stdio(false);
  //cin.tie(nullptr);
}
