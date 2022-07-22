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
    ll a, n; cin >> a >> n;

    queue<ll> que;
    vector<ll> dist(n*10+10, -1);

    que.emplace(1);
    dist[1] = 0;

    until(que.empty()) {
        ll curr = que.front(); que.pop();
        // debug(curr);

        string curr_str = to_string(curr);
        ll next1 = curr*a, next2 = n*10 + 100;
        if(curr%10 != 0 && curr > 10) next2 = stoll(curr_str.back() + curr_str.substr(0, curr_str.size()-1));

        if(next1 <= n*10 && dist[next1] == -1) {
            dist[next1] = dist[curr] + 1;
            que.emplace(next1);
        }
        if(next2 <= n*10 && dist[next2] == -1) {
            dist[next2] = dist[curr] + 1;
            que.emplace(next2);
        }
    }

    cout << dist[n] << endl;

    return 0;
}
