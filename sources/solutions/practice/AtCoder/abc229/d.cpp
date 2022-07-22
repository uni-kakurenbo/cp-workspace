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
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; ++i)
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
    string s; cin >> s;
    int k; cin >> k;

    vector<bool> v(size(s));
    REP(i, size(s)) v[i] = s[i] == '.';

    PrefixSum sum(ALL(v), 0);
    debug(sum);

    map<int,int> last_inds;
    REP(i, size(s)) {
        last_inds[sum[i]] = i+1;
    }
    last_inds[-1] = 0;
    last_inds[sum.back()] = size(sum);
    debug(last_inds);

    int left = -1, ans = 0;
    FOR(i, k, sum.back()+k) {
        int right = min(sum.back(), (int)i);
        debug(left, right, last_inds[left], last_inds[right], last_inds[right]-last_inds[left]);
        chmax(ans, last_inds[right]-last_inds[left]-1);
        left++;
    }
    cout << ans << endl;
    return 0;
}
