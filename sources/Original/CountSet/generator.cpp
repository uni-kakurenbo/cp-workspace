#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint998244353;

int solve(int n) {
    vector<mint> F(++n + 1);
    F[0] = F[1] = 1;
    for(int i=2; i<=n; ++i) {
        F[i] = F[i-1] + F[i-2];
    }
    return F[n].val();
}

random_device rd;
default_random_engine engine(rd());

signed main() {
    string dirName_in = "./testcases/in";
    string dirName_out = "./testcases/out";

    string fileName; cin >> fileName;
    ofstream ofs_in(dirName_in + "/" + fileName), ofs_out(dirName_out + "/" + fileName);

    if(!ofs_in || !ofs_out) {
        cout << "ファイルが開けませんでした。" << endl;
        return 0;
    }

    int m; cin >> m;
    uniform_int_distribution<int> distr(1, m);

    int n = distr(engine);

    ofs_in << n << endl;
    ofs_out << solve(n) << endl;

    return 0;
}
