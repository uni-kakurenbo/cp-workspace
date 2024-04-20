#include <iostream>
#include <vector>
#include <algorithm>

signed main() {
    int n; std::cin >> n;
    std::vector<long> a(n); for(auto& v : a) std::cin >> v;

    std::ranges::sort(a);

    long ans = 0;
    for(const long v : a) {
        ans *= 10;
        ans %= 998244353;

        ans += v;
        ans %= 998244353;
    }

    std::cout << ans << "\n";
}
