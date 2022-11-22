#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

signed main() {
    int N; cin >> N; N++;
    vector<atcoder::modint998244353> F(N+1);
    F[0] = F[1] = 1;
    for(int i=2; i <= N; ++i) F[i] = F[i-1] + F[i-2];
    cout << F[N].val() << endl;
    return 0;
}
