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
    ll h, w; cin >> h >> w;
    Matrix<bool> a(h, vector<bool> (w));
    REP(i, h) REP(j, w) {
        char c; cin >> c;
        a[i][j] = c=='#';
    }
    vector<ll> sumV(h), sumS(w);
    REP(i, h) REP(j, w) {
        sumV[i] += a[i][j];
        sumS[j] += a[i][j];
    }
    vector<bool> removedV(h), removedS(w);
    REP(i, h) {
        removedV[i] = sumV[i] == 0;
    }
    REP(i, w) {
    removedS[i] = sumS[i] == 0;
    }
    REP(i, h) {
        REP(j, w) {
            if(removedV[i] || removedS[j]) continue;
            cout << (a[i][j]?'#':'.');
        }
        cout << endl;
    }
}
