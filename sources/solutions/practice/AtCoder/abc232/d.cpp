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
#define FOR(i,a,b) for(int i=a, i##_last=int(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

signed main() {
    int h, w; cin >> h >> w;
    vector<string> grid(h);
    REP(i, h) cin >> grid[i];
    // bfs
    queue<pair<int,int>> que;
    vector<int> dist(h*w, -1);
    que.emplace(0, 0);
    dist[0] = 1;
    int di[2] = { 0, 1 }, dj[2] = { 1, 0 };
    int ans = 0;
    until(que.empty()) {
        auto [i, j] = que.front(); que.pop();
        chmax(ans, dist[i*w+j]);
        REP(d, 2) {
            int ni = i+di[d], nj = j+dj[d];
            if(ni >= h || nj >= w) continue;
            if(dist[ni*w+nj] > dist[i*w+j]) continue;
            if(grid[ni][nj] == '#') continue;
            dist[ni*w+nj] = dist[i*w+j] + 1;
            que.emplace(ni, nj);
        }
    }
    cout << ans << "\n";
    return 0;
}
