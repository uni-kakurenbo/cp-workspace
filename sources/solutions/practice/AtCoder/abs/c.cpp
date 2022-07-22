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
    int n, y; cin >> n >> y;
    int a, b, c;
    a = b = c = -1;
    y /= 1000;
    FOR(i, 0, 2000) {
        FOR(j, 0, 4000) {
            int k = n-i-j;
            if(i*10+j*5+k == y && k >= 0) {
                a = i, b = j, c = k;
                break;
            }
        }
    }
    printf("%i %i %i\n", a, b, c);
    return 0;
}
