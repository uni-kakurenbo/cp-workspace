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

#define F$ first
#define S$ second

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

template <class T = int> struct Matrix : vector<vector<T>> {
    Matrix(size_t height, size_t width) : vector<vector<T>> (height, vector<T> (width)) {}
    Matrix(size_t height, size_t width, T init) : vector<vector<T>> (height, vector<T> (width, init)) {}
    inline T& operator()(size_t i, size_t j) {return (*this)[i][j]; }
};

using PP = pair<int,int>;

map<char,int> hand = { { 'G', 0 }, { 'C', 1 }, { 'P', 2 } };

inline int judge(char a, char b) {
    return (hand[a] - hand[b] + 3) % 3; //Win:2, Lose:1
}

signed main() {
    int n, m; cin >> n >> m;
    Matrix<char> A(2*n, m);
    REP(i, 2*n) REP(j, m) cin >> A(i,j);
    vector<PP> standings(2*n);
    REP(i, 2*n) standings[i].S$ = i;
    REP(i, m) {
        REP(j, n) {
            int result = judge(A(standings[2*j].S$,i), A(standings[2*j+1].S$,i));
            standings[2*j].F$ -= result == 2;
            standings[2*j+1].F$ -= result == 1;
        }
        sort(ALL(standings));
        debug(standings);
    }
    REP(i, 2*n) cout << ++standings[i].S$ << "\n";
    return 0;
}
