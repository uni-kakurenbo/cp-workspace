#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_JUDGE
    #include<debug>
    using namespace Debug;
#else
    template<class T = nullptr_t, class S = nullptr_t> inline void debug(T = nllptr, S = nllptr) {}
#endif

using ll = long long;
using ull = unsigned long long;

#define REP(i,n) for(ll i=0, i##_length=ll(n); i<i##_length; ++i)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

ll MAX_PQ = 0;
ll MAX_AB = 0;

random_device rd;
default_random_engine engine(rd());
uniform_int_distribution<ll> distr2(0, 1);

pair<ll, ll> solve(ll P, ll Q) {
    auto q = sqrt(Q);
    ll l = floor(q), r = ceil(q);
    if(l*l == Q and r*r == Q) {
        return pair<ll, ll> (P+q, 0);
    }
    ll D = P*P - Q;
    if(D < 0ll) return pair<ll, ll> (-1, -1);
  	auto d = sqrt(D);
    l = floor(d), r = ceil(d);
    ll a = (P+l), b = (P-l);
    if(l*l == D && r*r == D && a%2==0) {
        return pair<ll, ll> (a/2, b/2);
    } else {
        return pair<ll, ll> (-1, -1);
    }
}


signed main() {
    string dirName_in = "./testcases/in";
    string dirName_out = "./testcases/out";

    string fileName; ll t, M1, M2; cin >> fileName >> t >> M1 >> M2;
    MAX_PQ = 1LL << M1, MAX_AB = 1LL << M2;
    uniform_int_distribution<ll> distrPQ(0, MAX_PQ-1);
    uniform_int_distribution<ll> distrAB(0, MAX_AB-1);

    ofstream ofs_in(dirName_in + "/" + fileName), ofs_out(dirName_out + "/" + fileName);
    if (!ofs_in || !ofs_out) {
        cout << "ファイルが開けませんでした。" << endl;
        cin.get();
        return 0;
    }

    ofs_in << t << endl;
    REP(i, t) {
        if(distr2(engine) == 0) {
            //debug("random");
            ll P = distrPQ(engine), Q = distrPQ(engine);
            ofs_in << P << " " << Q << endl;
            auto [a, b] = solve(P, Q);
            if(a == -1ll) {
                ofs_out << -1 << endl;
            } else {
                ofs_out << a << " " << b << endl;
            }
        } else {
            //debug("answer based");
            ll A, B, P, Q;
            do {
                A = distrAB(engine), B = distrAB(engine);
                P = A+B, Q = A*B*4;
            } while(P >= MAX_PQ || Q >= MAX_PQ);
            auto [a, b] = solve(P, Q);
            ofs_in << P << " " << Q << endl;
            ofs_out << a << " " << b << endl;
        }
    }
    return 0;
}
