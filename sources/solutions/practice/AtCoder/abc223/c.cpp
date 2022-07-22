#include <bits/stdc++.h>
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
    ll n; cin >> n;
    using Doukasen = pair<double,double>;
    vector<Doukasen> a(n);
    REP(i, n) cin >> a[i].first >> a[i].second;
    double time_sum = 0;
    REP(i, n) {
        time_sum += a[i].first/a[i].second;
    }
    double middle_time = time_sum/2.0;
    double now = 0, dist = 0;
    REP(i, n) {
        double next = a[i].first/a[i].second;
        if(now + next >= middle_time) {
            printf("%.16f\n", dist + (middle_time-now)*a[i].second);
            return 0;
        }
        dist += a[i].first;
        now += next;
    }
    return 0;
}
