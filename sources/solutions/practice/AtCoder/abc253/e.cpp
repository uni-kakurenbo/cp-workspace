#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_JUDGE
#include<debug>
    using namespace Debug;
#else
    template<class T = nullptr_t, class S = nullptr_t> inline void debug(T = nullptr, S = nullptr) {}
#endif

using ll = long long;
using ull = unsigned long long;

#define REP(i,n) for(ll i=0, i##_length=ll(n); i<i##_length; ++i)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

#include<atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

template <class T> struct Matrix : public vector<vector<T>> {
    Matrix(size_t height, size_t width) : vector<vector<T>> (height, vector<T> (width)) {}
    Matrix(size_t height, size_t width, T init) : vector<vector<T>> (height, vector<T> (width, init)) {}
};

template<class I, class T = typename iterator_traits<I>::value_type> struct PrefixSum : vector<T> {
    PrefixSum(I first, I last, T head = T()) : first(first), last(last) { build(head); }
    PrefixSum* build(T head = T()) {
        this->assign(distance(first,last) + 1, head);
        for(auto i=size_t(1), itr=first; itr != last; i++) {
            (*this)[i] = (*this)[i-1] + *(itr++);
        }
        return this;
    }
    inline T operator()(size_t left, size_t right) {
        return (*this)[right] - (*this)[left];
    }
  private:
    I first, last;
};

signed main() {
    ll n, m, k; cin >> n >> m >> k;
    Matrix<mint> dp(n+10, m+10, 0);
    FOR(i, 1, m) dp[1][i] = 1;
    FOR(i, 2, n) {
        PrefixSum sum(ALL(dp[i-1]));
        FOR(j, 1, m) {
            dp[i][j] += sum(1, max(j-k+1, 1LL)) + sum(min(j+k, m+1), m+1);
            if (k == 0) dp[i][j] -= dp[i-1][j];
        }
    }
    cout << reduce(ALL(dp[n]), mint(0)).val() << endl;
    return 0;
}
