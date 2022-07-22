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

int main() {
    ll n; cin >> n;
    vector<ll> a(n), b(n+1, 0), c(n+1, 0);
    REP(i, n) cin >> a[i];
    ll sum = reduce(ALL(a));
    ll sum_odd = 0;
    REP(i, n/2) sum_odd += a[i*2+1];
    vector<ll> res(n);
    res[0] = sum - 2*sum_odd;
    FOR(i, 1, n-1) res[i] = a[i-1]*2 - res[i-1];
    REP(i, n) printf("%lli ", res[i]);
    cout << endl;
    return 0;
}
