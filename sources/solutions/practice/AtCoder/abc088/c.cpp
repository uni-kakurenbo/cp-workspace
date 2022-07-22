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
    Matrix<int> c(3, vector<int> (3));
    REP(i, 3) REP(j, 3) cin >> c[i][j];
    ll sum = 0;
    REP(i, 3) REP(j, 3) sum += c[i][j];
    cout << (sum%3==0 && (c[0][0]+c[1][1]+c[2][2] == sum/3 )?"Yes":"No") << endl;
}
