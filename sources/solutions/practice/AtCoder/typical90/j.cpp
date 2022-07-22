#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

#define chmax(t, c) t = max(t, c)
#define chmin(t, c) t = min(t, c)

template <typename T>
using Matrix = vector<vector<T>>;

int main() {
    int n; cin >> n;
    vector<vector<int>> points(2, vector<int> (n));
    REP(i, n) {
        int c, p; cin >> c >> p;
        c--;
        points[c][i] = p;
    }
    vector<vector<int>> sums(2, vector<int> (n+1, 0));
    REP(c, 2) REP(i, n) {
        sums[c][i+1] = sums[c][i] + points[c][i];
    }
    int q; cin >> q;
    REP(i, q) {
        int l, r; cin >> l >> r;
        printf("%i %i\n", sums[0][r]-sums[0][l-1], sums[1][r]-sums[1][l-1]);
    }
    return 0;
}
