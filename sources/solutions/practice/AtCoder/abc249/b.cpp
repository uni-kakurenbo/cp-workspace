#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0, i##_len=ll(n); i<i##_len; i++)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

int main() {
    string s; cin >> s;
    set<char> st;
    string P = "ABCDEFGHIJKLMMOPQRSTUVWXYZ";
    string Q = "abcdefghijklmnopqrstuvwxyz";
    ll p=0, q=0;
    REP(i, s.size()) {
        st.insert(s[i]);
        if(count(ALL(P), s[i])) p++;
        if(count(ALL(Q), s[i])) q++;
    }
    if(st.size() != s.size()) {
        cout << "No" << endl;
        return 0;
    }
    if(p <= 0 || q <= 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}
