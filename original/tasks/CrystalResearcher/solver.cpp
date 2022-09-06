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

template <class T = int> struct UnfoldedMatrix : vector<T> {
    UnfoldedMatrix(size_t h = 0, size_t w = 0, T init = T()) : vector<T> (h*w, init), height(h), width(w), buffer_size(h*w) {};
    inline T& operator()(size_t i, size_t j) { return (*this)[i*width+j]; }
  private:
    size_t height, width, buffer_size;
};

signed main() {
    int h, w, n; cin >> h >> w >> n;
    string s; cin >> s;
    // debug(h,w,n,s.length());
    // debug(s);

    UnfoldedMatrix<int> grid(h+2, w+2, 1);


    int di[4] = { 0, 1, 0, -1 }, dj[4] = { 1, 0, -1, 0 };

    {
        int i=1, j=1, d=0;
        REP(k, n) {
            // debug(i,j);
            grid(i,j) = false;
            if(s[k] == 'F') i += di[d], j += dj[d];
            if(s[k] == 'L') --d;
            if(s[k] == 'R') ++d;
            if(s[k] == 'T') ++++d;
            d = mod(d,4);
        }
        grid(i,j) = false;
    }

    // REP(i,h+2) {
    //     REP(j,w+2) clog << (grid(i,j) ? "#" : ".");
    //     clog << "\n";
    // }

    int ans = 0;
    FOR(i, 1, h) FOR(j, 1, w) {
        short cnt = 0;
        if(!grid(i,j)) continue;
        REP(d, 4) if(grid(i+di[d],j+dj[d])) ++cnt;
        ans += cnt == 4;
    }

    cout << ans << "\n";

    return 0;
}
