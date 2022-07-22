#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL_JUDGE
    #include<debug>
    #define debug(...) do { Debug::debug(nullptr, "#" + to_string(__LINE__) + ": "); Debug::debug(__VA_ARGS__); } while(0);
#else
    #define debug(...) { ; }
#endif

using ll = long long;
using ull = unsigned long long;

#define until(...) while(!(__VA_ARGS__))

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define FOR(i,a,b) for(int i=a, i##_last=int(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((int)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

#define INF64 9223372036854775807LL

ll f(ll a, ll b) {
    return (a + b) * (a*a + b*b);
}

signed main() {
    ll n; cin >> n;
    int m = ceil(cbrt(n));
    ll ans = INF64;
    FOR(i, 0, m) {
        ll ng = -1, ok = m;
        while (abs(ok-ng) > 1) {
            ll mid = (ok+ng) / 2;
            (f(i, mid) >= n ? ok : ng) = mid;
        }
        chmin(ans, f(i, ok));
    }
    printf("%lli\n", ans);
    return 0;
}
