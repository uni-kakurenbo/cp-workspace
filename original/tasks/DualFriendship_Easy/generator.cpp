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

template <class T = int> struct UnfoldedMatrix : vector<T> {
    UnfoldedMatrix(size_t h = 0, size_t w = 0, T init = T()) : vector<T> (h*w, init), height(h), width(w), buffer_size(h*w) {};
    inline T& operator()(size_t i, size_t j) { return (*this)[i*width+j]; }
  private:
    size_t height, width, buffer_size;
};

template <class T> using Graph = vector<vector<T>>;

signed main() {
    string dirName_in = "./testcases/in";

    string fileName; cin >> fileName;
    ofstream ofs_in(dirName_in + "/" + fileName);

    int N, M; cin >> N >> M;
    if(N == -1) {
        uniform_int_distribution<int> distr_N(1, 3000);
        N = distr_N(engine);
    }
    if(M == -1) {
        uniform_int_distribution<int> distr_M(1, min(N*(N-1)/2, 3000));
        M = distr_M(engine);
    }
    if(M == -2) {
        M = min(3000, N*(N-1)/2);
    }
    assert(M <= N*(N-1)/2);

    debug(N, M);
    ofs_in << N << " " << M << "\n";

    uniform_int_distribution<int> distr_v(1, N);

    UnfoldedMatrix<int> already(N+1, N+1, false);
    Graph<int> G(N);
    FOR(i, 1, N) already(i,i) = true;

    for(int i=0; i<M; ) {
        int a = distr_v(engine), b = distr_v(engine);
        if(b < a) swap(a, b);

        if(already(a,b)) continue;

        // debug(a, b);
        ofs_in << a << " " << b << "\n";

        already(a,b) = true;
        G[a-1].emplace_back(b-1), G[b-1].emplace_back(a-1);

        ++i;
    }

    return 0;
}
