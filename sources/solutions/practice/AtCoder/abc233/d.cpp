#include <bits/stdc++.h>
using namespace std;

// #include <atcoder/...>
// using namespace atcoder;

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
#define FOR(i,a,b) for(int i=a, i##_last=int(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

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
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];
    PrefixSum sum(ALL(a));
    map<ll,ll> cnt;
    ll ans = 0;
    for(ll v : sum) {
        ans += cnt[v-x];
        cnt[v]++;
    }
    cout << ans << "\n";
    return 0;
}
