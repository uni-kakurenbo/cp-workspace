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
    int n; cin >> n;
    vector<string> a(n), b(n);
    REP(i, n) cin >> a[i] >> b[i];
    
    REP(i, n) {
        string p = a[i], q = b[i];
        bool ok = false;
        bool flag = true;
        REP(j, n) {
            if(i == j) continue;
            if(a[j] == p || b[j] == p) flag = false;
        }
        ok = ok || flag;
        flag = true;
        REP(j, n) {
            if(i == j) continue;
            if(a[j] == q || b[j] == q) flag = false;
        }
        ok = ok || flag;
        if(!ok) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
