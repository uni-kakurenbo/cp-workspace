#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

int main() {
    int n; cin >> n;
    vector<int> A(n);
    REP(i, n) cin >> A[i];
    int i=0;
    while(true) {
        if(!count(ALL(A), i)) {
            cout << i << endl;return 0;
        }
        i++;
    }
    return 0;
}
