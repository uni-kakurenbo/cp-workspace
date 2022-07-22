#include <bits/stdc++.h>
using namespace std;

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

#define INF32 2147483647

signed main() {
    int n; cin >> n;
    vector<int> x(n), y(n);
    REP(i, n) cin >> x[i] >> y[i];
    string dircs; cin >> dircs;
    map<int,int> right_min, left_max;
    REP(i, n) {
        if(!right_min.count(y[i])) right_min[y[i]] = INF32;
        if(dircs[i] == 'L') chmax(left_max[y[i]], x[i]);
        else chmin(right_min[y[i]], x[i]);
    }
    for(auto [k, v] : right_min) {
        if(left_max[k] > v) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
