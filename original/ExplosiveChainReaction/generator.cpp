/*
 * @uni_kakurenbo
 * https://github.com/uni-kakurenbo/competitive-programming-workspace
 *
 * CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja
 */
/* #language C++ GCC */
/* #region tmplate */
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_JUDGE
    #include<debug>
    #define debug(...) Debug::debug(Debug::split(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
    #define DEBUG(...) do { Debug::DEBUG(nullptr, "\033[3;35m#" + to_string(__LINE__) + "\033[m  "); Debug::DEBUG(__VA_ARGS__); Debug::DEBUG(nullptr, "\033[m\n"); } while(0);
#else
    #define debug(...) { ; }
    #define DEBUG(...) { ; }
#endif

#define INF32 2147483647
#define INF64 9223372036854775807LL

#define until(...) while(!(__VA_ARGS__))

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define REPD(i,n) for(int i=(n)-1; i>=0; --i)
#define FOR(i,a,b) for(ll i=(a), i##_last=ll(b); i<=i##_last; ++i)
#define FORD(i,a,b) for(ll i=(a), i##_last=ll(b); i>=i##_last; --i)

#define ALL(x) begin((x)),end((x))
#define RALL(x) rbegin((x)),rend((x))

#define F$ first
#define S$ second

using ll = long long;
using ull = unsigned long long;
using ld = long double;

template<class T> inline T mod(T x, T r) { return (x%r+r)%r; }

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }
/* #endregion */

random_device rd;
default_random_engine engine(rd());

template <class T> using Graph = vector<vector<T>>;

signed main() {
    string dirName_in = "./testcases/in";

    string fileName; cin >> fileName;
    ofstream ofs_in(dirName_in + "/" + fileName);

    int N, r, L, p; cin >> N >> r >> L >> p;
    if(N == -1) {
        uniform_int_distribution<int> distr_N(1, 3000);
        N = distr_N(engine);
    }
    if(r == -1) {
        ld d = 2.0L * L / sqrt(N);
        uniform_int_distribution<int> distr_r(0.98 * d, 1.3 * d);
        r = distr_r(engine);
    }
    if(p == -1) {
        uniform_int_distribution<int> distr_p(log10(N), log2(N));
        p = distr_p(engine);
    }
    if(p == -2) {
        uniform_int_distribution<int> distr_p(1, 1.5*N);
        p = distr_p(engine);
    }

    uniform_int_distribution<int> distr_xy(-L, L);

    ofs_in << N << " " << r << "\n";
    debug(N, r, L, p);

    vector<pair<int,int>> bombs(N);

    REP(i, N) {
        int x = distr_xy(engine), y = distr_xy(engine);
        bombs.emplace_back(x, y);
        ofs_in << x << " " << y << "\n";
        // clog << x << "," << y << "\n";
    }


    string S(N, 'N');
    uniform_int_distribution<int> distr_S_pos(0, N-1);
    REP(i, p) {
        int pos = distr_S_pos(engine);
        S[pos] = 'Y';
    }

    ofs_in << S << "\n";

    return 0;
}
