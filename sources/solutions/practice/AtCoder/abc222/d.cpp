#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

#ifdef LOCAL_JUDGE
    #include<debug>
    #define debug(...) Debug::debug(Debug::split(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
    #define DEBUG(...) do { Debug::DEBUG(nullptr, "#" + to_string(__LINE__) + "  "); Debug::DEBUG(__VA_ARGS__); Debug::DEBUG(nullptr, "\033[m"); } while(0);
#else
    #define debug(...) { ; }
    #define DEBUG(...) { ; }
#endif

using ll = long long;
using ull = unsigned long long;

#define until(...) while(!(__VA_ARGS__))

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)

#define F$ first
#define S$ second

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

using mint = modint998244353;

template <class T = int> struct Matrix : vector<vector<T>> {
    Matrix(size_t height, size_t width, T init = T()) : vector<vector<T>> (height, vector<T> (width, init)) {}
    inline T& operator()(size_t i, size_t j) {return (*this)[i][j]; }
};

template<class I, class T = typename iterator_traits<I>::value_type> struct PrefixSum : vector<T> {
    PrefixSum(I first, I last, T head = T()) : first(first), last(last) { build(head); }
    PrefixSum* build(T head = T()) {
        this->assign(distance(first,last) + 1, head);
        for(auto i=size_t(1), itr=first; itr != last; i++) {
            (*this)[i] = (*this)[i-1] + *itr++;
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
    int n; cin >> n;
    vector<int> a(n), b(n);
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];
    Matrix<mint> dp(n+1, 3001);
    dp(0, 0) = 1;
    REP(i, n) {
        PrefixSum sum(ALL(dp[i]));
        FOR(j, a[i], b[i]) dp(i+1, j) = sum(0, j+1);
    }
    cout << reduce(ALL(dp[n])).val() << endl;
    return 0;
}
