#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

#define chmax(t, c) t = max(t, c)
#define chmin(t, c) t = min(t, c)

int main() {
    int n; cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    int ans = 10e10;
    REP(i, n) {
        int cnt = 0;
        while(a[i] % 2 == 0) {
            a[i] /= 2;
            cnt++;
        }
        chmin(ans, cnt);
    }
    printf("%i", ans);
    return 0;
}
