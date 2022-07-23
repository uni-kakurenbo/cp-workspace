#include <bits/stdc++.h>
using namespace std;

#include <atcoder/dsu>
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

struct Circle {
    int x, y, r;
    Circle(int x = 0, int y = 0, int r = 0) : x(x), y(y), r(r) {};
    bool is_connected(Circle *other) {
        int dx = this->x - other->x, dy = this->y - other->y;
        ll d = 1LL*dx*dx + 1LL*dy*dy;
        ll p = this->r - other->r, q = this->r + other->r;
        return p*p <= d && d <= q*q;
    }
    bool on_circumference(int x, int y) {
        int dx = this->x - x, dy = this->y - y;
        ll d = 1LL*dx*dx + 1LL*dy*dy;
        debug(d, 1LL*this->r*this->r);
        return d == 1LL*this->r*this->r;
    }
    vector<int> _debug() {
        return { x, y, r };
    }
};

signed main() {
    int n; cin >> n;
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;

    vector<Circle> circles(n);
    REP(i, n) cin >> circles[i].x >> circles[i].y >> circles[i].r;
    debug(circles);

    dsu uf(n);

    int s = 0, t = 0;
    FOR(i, 0, n-1) {
        if(circles[i].on_circumference(sx, sy)) s = i;
        if(circles[i].on_circumference(tx, ty)) t = i;
        FOR(j, i+1, n-1) {
            if(circles[i].is_connected(&circles[j])) uf.merge(i, j);
        }
    }
    debug(s,t);

    cout << (uf.same(s,t) ? "Yes" : "No") << "\n";

    return 0;
}
