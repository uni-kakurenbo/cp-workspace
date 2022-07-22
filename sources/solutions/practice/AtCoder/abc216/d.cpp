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
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)

#define F$ first
#define S$ second

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

signed main() {
    int n, m; cin >> n >> m;
    vector<queue<int>> pipes(m);

    REP(i, m) {
        int k; cin >> k;
        REP(j, k) {
            int a; cin >> a;
            pipes[i].emplace(a);
        }
    }

    map<int,vector<int>> cnt;
    REP(i, m) cnt[pipes[i].front()].emplace_back(i);
    debug(cnt);

    set<int> erasables;
    FOR(i, 1, n) if(cnt[i].size() > 1) erasables.emplace(i);

    until(erasables.empty()) {
        int i = *erasables.begin(); erasables.erase(erasables.begin());
        debug(i, cnt[i]);

        pipes[cnt[i][0]].pop(), pipes[cnt[i][1]].pop();

        int i0 = 0, i1 = 0;
        if(!pipes[cnt[i][0]].empty()) { i0 = pipes[cnt[i][0]].front(); }
        if(!pipes[cnt[i][1]].empty()) { i1 = pipes[cnt[i][1]].front(); }

        if(i0) cnt[i0].emplace_back(cnt[i][0]);
        if(i1) cnt[i1].emplace_back(cnt[i][1]);

        cnt.erase(i);

        if(i0 && cnt[i0].size() > 1) erasables.insert(i0);
        if(i1 && cnt[i1].size() > 1) erasables.insert(i1);
    }

    int remained = accumulate(ALL(pipes), 0, [](int acc, auto &e) { return acc + e.size(); });
    cout << (remained == 0 ? "Yes" : "No") << "\n";

    return 0;
}
