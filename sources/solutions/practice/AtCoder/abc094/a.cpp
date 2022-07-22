#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int a, b, x; cin >> a >> b >> x;
    cout << (b>=x-a&&x-a>=0?"YES":"NO") << endl;
    return 0;
}
