#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 2147483647

#define REP(i,n) for(int i=0; i<int(n); i++)

using Matrix = vector<vector<int>>;

int main() {
    int n; cin >> n;
    Matrix C(n, vector<int> (n));
    REP(i, n) REP(j, n) cin >> C[i][j];

    vector<int> E(n);
    int row_min = INF;
    REP(i, n) {
        row_min = min(row_min, C[i][0]);
    }
    REP(i, n) {
        E[i] = C[i][0] - row_min;
    }

    vector<int> B(n);
    REP(i, n) {
        B[i] = C[0][i] - E[0];
        if(B[i] < 0) {
            cout << "No" << endl;
            return 0;
        };
    }

    REP(i, n) REP(j, n) {
        if(C[i][j] != E[i] + B[j]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    REP(i, n) cout << E[i] << " ";
    cout << endl;
    REP(i, n) cout << B[i] << " ";
    cout << endl;
    return 0;
}
