#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,a,b) for(int i=a; i<=int(b); i++)
#define FORA(i,I) for(auto& i:I)

int main() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    FORA(v, a) cin >> v;
    FORA(v, b) cin >> v;

    int ans = 0;
    REP(i, n) {
        if(a[i] == b[i]) ans++;
    }
    cout << ans << endl;

    ans = 0;
    REP(i, n) REP(j, n) {
        if(i != j && a[i] == b[j]) ans++;
    }
    cout << ans << endl;

    return 0;
}
