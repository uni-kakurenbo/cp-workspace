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
    ll n, m; cin >> n >> m;
    // cost, nums
    using Stored = pair<ll, ll>;
    vector<Stored> p(n);
    REP(i, n) {
        cin >> p[i].first >> p[i].second;
    }
    sort(ALL(p));

    ll cost = 0;
    ll bought = 0;
    REP(i, n) {
        cost += p[i].first * p[i].second;
        bought += p[i].second;
        if(bought >= m) {
            cost -= p[i].first * (bought - m);
            break;
        }
    }
    printf("%lli\n", cost);

    return 0;
}
