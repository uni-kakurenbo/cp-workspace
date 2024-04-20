#include <iostream>
#include <algorithm>
#include <vector>
#include <ranges>

signed main() {
    int n, m, w; std::cin >> n >> m >> w;
    std::vector<int> a(n), b(m), c(m);

    for(auto& v : a) std::cin >> v;
    for(auto& v : b) std::cin >> v;
    for(auto& v : c) std::cin >> v;

    std::ranges::sort(a, [&](int x, int y) { return y < x; });
    std::vector<long> cum_a(n + 1);
    for(const int i : std::views::iota(0, n)) cum_a[i + 1] = cum_a[i] + a[i];

    long ans = 0;

    for(const int x : std::views::iota(0U, 1U << m)) {
        long ws = 0, vs = 0;
        for(const int i : std::views::iota(0, m)) {
            if((x >> i) & 1) continue;
            ws += b[i];
            vs += c[i];
        }

        if(ws > w) continue;

        long pro = vs + cum_a[std::min<long>(w - ws, n)];

        if(ans < pro) ans = pro;
    }

    std::cout << ans << "\n";
}
