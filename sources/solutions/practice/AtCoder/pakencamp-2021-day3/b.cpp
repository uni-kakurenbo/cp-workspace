#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

#define chmax(t, c) a = max(t, c)
#define chmin(t, c) a = min(t, c)

int main() {
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> A(n);
    ll sum = 0;
    REP(i, n) {
        cin >> A[i];
        sum += A[i];
    }
    if(sum != x+y) {
        cout << "No" << endl;
        return 0;
    }
    ll target = min(x, y);
    ll current = A[0];
    ll r = 1;
    REP(l, n) {
        while(r <= 2*n && current <= target) {
            //printf("%i - %i : %i\n", l, r, current);
            if(current == target) {
                cout << "Yes" << endl;
                return 0;
            }
            current += A[r%n];
            ++r;
        }
        current -= A[l];
    }
    cout << "No" << endl;
    return 0;
}
