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

template<class T = int> struct Primes : vector<T> {
    Primes(size_t max) : is_prime(max+1, true) {
        is_prime[0] = is_prime[1] = false;
        for(size_t p=2; p<=max; p++) if(is_prime[p]) {
            for(size_t i=p*p; i<=max; i+=p) is_prime[i] = false;
            this->emplace_back(p);
        }
    }
    bool operator()(size_t index) {
        return is_prime[index];
    }
  private:
    vector<bool> is_prime;
};

signed main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    Primes primes(300);
    int max_np = 0, np = 0;
    FOR(i, a+c, b+d) {
        if(primes(i)) np = 0;
        else np++;
        chmax(max_np, np);
    }
    cout << (max_np <= d-c ? "Aoki" : "Takahashi") << endl;
    return 0;
}
