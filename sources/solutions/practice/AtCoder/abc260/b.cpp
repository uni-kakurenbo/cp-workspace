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
#define REPD(i,n) for(int i=n-1; i>=0; --i)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; ++i)
#define FORD(i,a,b) for(ll i=a i##_stop=ll(b); i>=i##_stop; --i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)

#define F$ first
#define S$ second

#define R$(x,r) ((x)%(r)+(r))%(r)

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

signed main() {
    int n, x, y, z; cin >> n >> x >> y >> z;

    vector<pair<int,int>> a(n), b(n), c(n);
    vector<bool> alr(n);

    REP(i, n) cin >> a[i].F$, a[i].S$ = -i;
    REP(i, n) cin >> b[i].F$, b[i].S$ = -i;
    REP(i, n) c[i].F$ = a[i].F$ + b[i].F$, c[i].S$ = -i;
    debug(a, b, c);

    sort(RALL(a)), sort(RALL(b)), sort(RALL(c));

    vector<int> ans;
    int cnt;

    cnt = 0;
    REP(i, n) {
        if(++cnt > x) continue;
        alr[-a[i].S$] = true;
        ans.emplace_back(-a[i].S$);
    }
    cnt = 0;
    REP(i, n) {
        if(alr[-b[i].S$] || ++cnt > y) continue;
        alr[-b[i].S$] = true;
        ans.emplace_back(-b[i].S$);
    }
    cnt = 0;
    REP(i, n) {
        if(alr[-c[i].S$] || ++cnt > z) continue;
        alr[-c[i].S$] = true;
        ans.emplace_back(-c[i].S$);
    }

    sort(ALL(ans));

    FORA(v, ans) cout << ++v << "\n";

    return 0;
}
