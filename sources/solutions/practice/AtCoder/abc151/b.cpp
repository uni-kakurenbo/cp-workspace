#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i,n) for(int i=0; i<int(n); i++)

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    int sum = 0;
    REP(i, n-1) {
        int a; cin >> a;
        sum += a;
    }
    int ans = max(0, m*n-sum);

    cout << (ans<=k?ans:-1) << endl;
    return 0;
}
