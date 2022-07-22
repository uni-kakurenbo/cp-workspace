#include <bits/stdc++.h>
using namespace std;

// #include <atcoder/...>
// using namespace atcoder;

#ifdef LOCAL_JUDGE
    #include<debug>
    #define debug(...) Debug::debug(Debug::split(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
    #define DEBUG(...) do { Debug::DEBUG(nullptr, "\033[3;35m#" + to_string(__LINE__) + "\033[m  "); Debug::DEBUG(__VA_ARGS__); Debug::DEBUG(nullptr, "\033[m\n"); } while(0);
#else
    #define debug(...) { ; }
    #define DEBUG(...) { ; }
#endif

using ll = long long;
using ull = unsigned long long;

#define INF32 2147483647
#define INF64 9223372036854775807LL

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

template<class T> vector<T> divisors(T n) {
    vector<T> res;
    for (T i=1; i*i<=n; i++) {
        if (n%i == 0) {
            res.emplace_back(i);
            if(i*i < n) res.emplace_back(n/i);
        }
    }
    sort(ALL(res));
    return res;
}

signed main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    REP(i, n) cin >> a[i];

    vector<int> ok(m+1, true);
    ok[0] = 0;
    REP(i, n) {
        vector divs = divisors(a[i]);
        FORA(div, divs) if(div != 1 && div <= m && ok[div]) {
            int d = div;
            while(d <= m) ok[d] = false, d += div;
        }
    }
    debug(ok);

    cout << reduce(ALL(ok)) << "\n";
    FOR(i, 1, m) if(ok[i]) cout << i << "\n";

    return 0;
}
