#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL_JUDGE
    #include<debug>
    using namespace Debug;
#else
    template<class T = nullptr_t, class S = nullptr_t> inline void debug(T = nullptr, S = nullptr) {}
#endif

using ll = long long;

#define REP(i,n) for(ll i=0, i##_length=ll(n); i<i##_length; ++i)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

template <class T> struct Matrix : public vector<vector<T>> {
  Matrix(size_t height, size_t width) : vector<vector<T>> (height, vector<T> (width)) {}
  Matrix(size_t height, size_t width, T init) : vector<vector<T>> (height, vector<T> (width, init)) {}
};

int main() {
  ll n; cin >> n;
  vector<string> S(n);
  Matrix<ll> inds(10, n, -1);

  REP(i, n) {
    cin >> S[i];
  }

  REP(i, n) {
    REP(j, 10) {
      ll x = S[i][j]-'0';
      ll cnt = 0;
      for(auto ind : inds[x]) {
        cnt += ind%10 == j;
      }
      inds[x][i] = j + 10*cnt;
    }
  }

  vector<ll> mxs(10);
  REP(i, 10) {
    auto mx = max_element(ALL(inds[i]));
    mxs[i] = *mx;
  }
  debug(S);
  debug(mxs);

  cout << *min_element(ALL(mxs)) << endl;

  return 0;
}
