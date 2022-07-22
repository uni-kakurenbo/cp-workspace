#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> blue(n);
    for (int i = 0; i < n; i++) {
        cin >> blue[i];
    }
    int m;
    cin >> m;
    vector<string> red(m);
    for (int i = 0; i < m; i++) {
        cin >> red[i];
    }

    int ans = 0;
    auto calc = [&](string s) {
        int buf = 0;
        for (string t: blue) {
            if (t == s) buf++;
        }
        for (string t: red) {
            if (t == s) buf--;
        }
        return buf;
    };

    for (string t: blue) {
        ans = max(ans, calc(t));
    }

    cout << ans << endl;
    return 0;
}

