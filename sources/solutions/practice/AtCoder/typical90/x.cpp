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
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];
    int cnt = 0;
    REP(i, n) {
        cnt += abs(a[i]-b[i]);
    }
    bool ans = cnt <= k && (k-cnt)%2 == 0;
    cout << (ans?"Yes":"No") << endl;
    return 0;
}
