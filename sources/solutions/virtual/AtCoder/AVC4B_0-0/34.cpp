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
#define FORD(i,a,b) for(ll i=a, i##_last=ll(b); i>=i##_last; --i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)

#define F$ first
#define S$ second

#define R$(x,r) ((x)%(r)+(r))%(r)

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

signed main() {
    int h, w; cin >> h >> w;
    vector<string> maze(h); REP(i, h) cin >> maze[i];
    debug(maze);

    int di[4] = { 0, 0, 1, -1 }, dj[4] = { -1, 1, 0, 0 };
    auto bfs = [&](int si, int sj, vector<int> &dists) {
        queue<pair<int,int>> que;
        que.emplace(si, sj), dists[si*w+sj] = 0;

        while(!que.empty()) {
            auto [i,j] = que.front(); que.pop();
            REP(d, 4) {
                int ni = i + di[d], nj = j + dj[d];
                if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                if(maze[ni][nj] == '#') continue;
                if(dists[ni*w+nj] >= 0) continue;
                dists[ni*w+nj] = dists[i*w+j] + 1;
                que.emplace(ni, nj);
            }
        }
        return;
    };

    int ans = -1;

    REP(si, h) REP(sj, w) {
        if(maze[si][sj] == '#') continue;
        vector<int> dists(h*w, -1);
        bfs(si, sj, dists);
        REP(gi, h) REP(gj, w) {
            if(maze[gi][gj] == '#') continue;
            chmax(ans, dists[gi*w+gj]);
        }
    }

    cout << ans << "\n";

    return 0;
}
