#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL_JUDGE
    #include<debug>
    #define debug(...) do { Debug::debug(nullptr, "#" + to_string(__LINE__) + ": "); Debug::debug(__VA_ARGS__); } while(0);
#else
    #define debug(...) { ; }
#endif

using ll = long long;
using ull = unsigned long long;

#define until(...) while(!(__VA_ARGS__))

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define FOR(i,a,b) for(int i=a, i##_last=int(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((int)(x).size())

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
    ll n; cin >> n;
    Primes primes(ceil(cbrt(n)));
    ll ans = 0;
    FOR(i, 1, primes.size()-1) {
        ll q = primes[i];
        FOR(j, 0, i-1) {
            ll p = primes[j];
            if(p * q*q*q > n) break;
            ans++;
        }
    }
    printf("%lli\n", ans);
    return 0;
}
