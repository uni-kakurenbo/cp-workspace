#include <bits/stdc++.h>
#include<atcoder/modint>

using namespace std;
using namespace atcoder;

using ll = long long;
using mint = modint998244353;

#define REP(i,n) for(ll i=0, i##_len=ll(n); i<i##_len; i++)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> bool chmax(T& a, T b) { a = std::max(a, b); return a < b; }
template<class T> bool chmin(T& a, T b) { a = std::min(a, b); return a > b; }

template <class T = int> struct UnfoldedMatrix : vector<T> {
    UnfoldedMatrix(size_t h = 0, size_t w = 0, T init = T()) : vector<T> (h*w, init), height(h), width(w), buffer_size(h*w) {};
    inline T& operator()(size_t i, size_t j) { return (*this)[i*width+j]; }
  private:
    size_t height, width, buffer_size;
};

int main() {
    ll n, m, k; cin >> n >> m >> k;
    UnfoldedMatrix<mint> dp(n+10, k+10, 0);

    dp(0,0) = 1;
    REP(i, n) {
        FOR(p, 0, k) {
            FOR(q, 1, m) {
                if(p+q <= k) dp(i+1,p+q) += dp(i,p);
            }
        }
    }

    mint ans;
    FOR(i, 0, k) ans += dp(n,i);

    cout << ans.val() << endl;

    return 0;
}
