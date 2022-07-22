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

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

struct Train {
    int id;
    Train *front = nullptr, *back = nullptr;
    Train(int id = 0) : id(id) {}
};

signed main() {
    int n, q; cin >> n >> q;
    vector<Train> trains(n);
    REP(i, n) trains[i] = i;
    REP(i, q) {
        short com; cin >> com;
        if(com == 1) {
            int x, y; cin >> x >> y; --x, --y;
            trains[x].back = &trains[y], trains[y].front = &trains[x];
        }
        if(com == 2) {
            int x, y; cin >> x >> y; --x, --y;
            trains[x].back = nullptr, trains[y].front = nullptr;
        }
        if(com == 3) {
            int x; cin >> x; --x;
            Train *curr = &trains[x];
            until(curr->front == nullptr) curr = curr->front;
            vector<int> ans;
            until(curr == nullptr) ans.emplace_back(curr->id), curr = curr->back;
            cout << size(ans) << " ";
            FORA(id, ans) cout << id+1 << " ";
            cout << "\n";
        }
    }
    return 0;
}
