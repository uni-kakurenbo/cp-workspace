#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0, i##_length=ll(n); i<i##_length; i++)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

template <class T> struct Matrix : public vector<vector<T>> {
    Matrix(size_t height, size_t width) : vector<vector<T>> (height, vector<T> (width)) {}
    Matrix(size_t height, size_t width, T init) : vector<vector<T>> (height, vector<T> (width, init)) {}
};

int main() {
    int n, k; cin >> n >> k;
    ll ans = k * pow(k-1, n-1);
    printf("%lli\n", ans);
    return 0;
}
