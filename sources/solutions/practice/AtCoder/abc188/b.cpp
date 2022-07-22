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
    vector<int> a(n), b(n);
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];
    int sum = 0;
    REP(i, n) {
        sum += a[i]*b[i];
    }
    cout << (sum == 0 ? "Yes":"No") << endl;
    return 0;
}
