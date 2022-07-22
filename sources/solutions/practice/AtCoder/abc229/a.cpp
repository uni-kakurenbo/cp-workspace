#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0, i##_length=ll(n); i<i##_length; i++)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

int main() {
    string s0, s1; cin >> s0 >> s1;
    if(
        s0[0] == '#' && s0[1] == '#' ||
        s0[0] == '#' && s1[0] == '#' ||
        s0[1] == '#' && s1[1] == '#' ||
        s1[0] == '#' && s1[1] == '#'
    ) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
