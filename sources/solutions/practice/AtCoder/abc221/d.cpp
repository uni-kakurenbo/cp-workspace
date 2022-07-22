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

signed main() {
    int n; cin >> n;
    map<int,int> timeline;
    REP(i, n) {
        int a, b; cin >> a >> b;
        timeline[a] += 1, timeline[a+b] -= 1;
    }
    timeline[0] = 0;
    debug(timeline);

    int cnt = 0;
    vector<int> ans(n+1);
    for(auto itr = ++begin(timeline); itr!=end(timeline); ++itr) {
        auto [time,diff] = *itr;
        debug(time, diff, cnt);
        ans[cnt] += time - prev(itr)->F$;
        cnt += diff;
    }
    debug(ans);

    FOR(i, 1, n) cout << ans[i] << " ";

    return 0;
}
