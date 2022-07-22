#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0, i##_length=ll(n); i<i##_length; ++i)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

int main() {
    ll n, w; cin >> n >> w;
    vector<ll> a;
    set<ll> st;
    REP(i, n) {
        ll x; cin >> x;
        if(x <= w) a.emplace_back(x), st.insert(x);
    }
    n = a.size();
    FOR(i, 0, n-1) FOR(j, i+1, n-1) {
        ll sum = a[i] + a[j];
        if(sum <= w) st.insert(sum);
    }
    FOR(i, 0, n-1) FOR(j, i+1, n-1) FOR(k, j+1, n-1) {
        ll sum = a[i] + a[j] + a[k];
        if(sum <= w) st.insert(sum);
    }
    cout << st.size() << endl;
    return 0;
}
