#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0, i##_len=ll(n); i<i##_len; i++)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> bool chmax(T& a, T b) { a = std::max(a, b); return a < b; }
template<class T> bool chmin(T& a, T b) { a = std::min(a, b); return a > b; }

int main() {
    vector<ll> s(100);
    REP(i, 9) {
        char c; cin >> c;
        s[c-'0']++;
    }
    REP(i, 10) {
        if(s[i] == 0) {
            cout << i << endl;
        }
    }
    return 0;
}
