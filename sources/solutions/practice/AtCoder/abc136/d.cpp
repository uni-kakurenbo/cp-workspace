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
    string s; cin >> s;
    s = "!" + s + "!";
    int n = s.size();
    vector<int> ans(n);
    FOR(i, 1, n-2) {
        if(s[i] == 'R' and s[i+1] == 'L' or s[i] == 'L' and s[i-1] == 'R') {
            int j = i - 2;
            int cnt = 0;
             while(0 <= j and s[j] == 'R') {
                if(s[j+1] == 'L') break;
                ++cnt, j -= 2;
            }
            j = i + 2;
            while(j < n and s[j] == 'L') {
                if(s[j-1] == 'R') break;
                ++cnt, j += 2;
            }
            ans[i] = ++cnt;
        }
    }
    FOR(i, 1, n-2) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
