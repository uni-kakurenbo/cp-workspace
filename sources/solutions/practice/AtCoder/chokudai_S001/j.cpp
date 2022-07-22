#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0, i##_len=ll(n); i<i##_len; i++)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> bool chmax(T& a, T b) { a = std::max(a, b); return a < b; }
template<class T> bool chmin(T& a, T b) { a = std::min(a, b); return a > b; }

template<class T> struct BIT {
    BIT(size_t size) : n(++size), bits(n, 0) {}

    BIT& add(size_t target, T x) {
        for(size_t i=target; i < this->n; i += -i&i) {
            this->bits[i] += x;
        }
        return *this;
    }

    T sum(size_t last) {
        T res(0);
        for (size_t i=last; i>0; i -= -i&i) {
            res += this->bits[i];
        }
        return res;
    }

  private:
    size_t n;
    vector<T> bits;
};

signed main() {
    int n; cin >> n;
    vector<int> v(n);
    REP(i, n) { cin >> v[i]; }
 
    ll ans = 0;
    BIT<int> b(n);
    REP(i, n) {
        ans += i - b.sum(v[i]);
        b.add(v[i], 1);
    }
    cout << ans << endl;
}
