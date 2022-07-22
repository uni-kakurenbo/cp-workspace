#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    tuple<int, int, int> T(a, b, 0), A(c, d, 1);
    if(T < A) {
        cout << "Takahashi";
    } else {
        cout << "Aoki";
    }
    cout << endl;
    return 0;
}
