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
    int h, w; cin >> h >> w;
    Matrix<int> A(h, vector<int> (w));
    REP(i, h) REP(j, w) cin >> A[i][j];
    REP(j, w) {
        REP(i, h) cout << A[i][j] << " ";
        cout << endl;
    }
    return 0;
}
