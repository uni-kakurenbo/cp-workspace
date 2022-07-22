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
#define FOR(i,a,b) for(int i=a, i##_last=int(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

using mint = modint998244353;

ll sum1to(__int128_t last) {
  return (last) * (last+1) / 2 % 998244353;
}

signed main() {
    ll n; cin >> n;
    mint ans = 0;
    ll p = 1, prev_p;
    FOR(d, 1, 18) {
        prev_p = p, p *= 10;
        if(p > n) break;
        ans += sum1to(p - prev_p);
    }
    ans += sum1to(n - prev_p + 1);
    cout << ans.val() << endl;
    return 0;
}
