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
#define FORD(i,a,b) for(ll i=a, i##_stop=ll(b); i>=i##_stop; --i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)

#define F$ first
#define S$ second

#define R$(x,r) ((x)%(r)+(r))%(r)

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }


signed main() {
    int n, k; cin >> n >> k;
    vector<int> p(n); REP(i, n) cin >> p[i];

    map<int,long> stage; // {トップのカード, 積まれている枚数}
    vector<int> ans(n+1); // 答えを保持する配列

    REP(i, n) {
        int v = p[i];
        auto itr = stage.lower_bound(v);  // 積むべきカードを探してくる。

        if(itr == stage.end()) {  // 見つからなかったら。
            stage.emplace(v, 1);  // 新たに追加。(1枚だけ重なっている)
        } else { // 見つかったらトップを書き換える。
            stage[v] = itr->S$ + 1;  // 実際には，新たに追加して，
            ans[v] = ans[itr->F$] < 0 ? ans[itr->F$] : -itr->F$;  // (後述) ☆1
            stage.erase(itr);  // 古い方を消す。
        }

        if(stage[v] >= k) {  // K 枚を超えたら，
            (ans[v] < 0 ? ans[-ans[v]] : ans[v]) = i+1;  // 答えを書き換えて，
            stage.erase(v);  // その束を食べる。
        }

        debug(stage); debug(ans);
    }

    // ans[i] には通常，「そのカードが食べられたターン」を書き込む。
    // ただし，カードの上に別なカードを重ねるとき，
    // その束はまとめて同時に食べられるので，
    // 一番底にある(最初に置かれた)カード以外については，
    // 実際の答えの代わりに，「どのカードと同時に食べられるのか」を保存して，
    // 答えを出力する際にそのカードの答えを参照する。(☆2 の部分)
    // これらは，後者を，__符号を反転させて__保存することで区別ができる。 (☆1 の部分)

    FOR(i, 1, n) {
        int v = ans[i];
        if(v < 0) v = ans[-v];  //  ans[i] が負なら，参照先の答えを持ってくる。 ☆2
        cout << (v == 0 ? -1 : v) << "\n";
    }

    return 0;
}
