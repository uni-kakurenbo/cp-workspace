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

signed main() {
    string dirName_in = "./testcases/in";

    string fileName; cin >> fileName;
    ofstream ofs_in(dirName_in + "/" + fileName);

    int H, W, N, p; cin >> H >> W >> N >> p;
    string S;

    uniform_int_distribution<int> distr_S(0, 3+p);


    int di[4] = { 0, 1, 0, -1 }, dj[4] = { 1, 0, -1, 0 };

    int i = 0, j = 0, d = 0, pr_d = -1;
    for(int k=0; k<N; ) {
        int m = distr_S(engine);
        int pd=d, p_pr_d = pr_d;
        if(m == 1) S += 'L', --d;
        if(m == 2) S += 'R', ++d;
        if(m == 3) S += 'T', ++++d;
        d = mod(d,4);
        if(m > 3) S += 'F', i += di[d], j += dj[d];
        // debug(d, i, j);
        if(m == pr_d || i < 0 || i >= H || j < 0 || j >= W) {
            S.pop_back();
            chmax(i, 0), chmin(i, H-1), chmax(j, 0), chmin(j, W-1);
            d = pd, pr_d = p_pr_d;
            continue;
        }
        ++k;

        if(m == 1) pr_d = 2;
        if(m == 2) pr_d = 1;
        if(m == 3) pr_d = 3;
        if(m > 3) pr_d = -1;
    }

    debug(H, W, N);
    // debug(S);
    ofs_in << H << " " << W << " " << N << endl << S << endl;
    // cout << H << " " << W << " " << N << endl << S << endl;

    return 0;
}
