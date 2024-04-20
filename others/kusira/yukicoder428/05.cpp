#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

#include <atcoder/modint>

#include "numeric/leveler.hpp"
#include "template/debug.hpp"

using mint = atcoder::modint998244353;


signed main() {
    int n, m, k; std::cin >> n >> m >> k;

    std::vector<std::vector<int>> to(n);
    for([[maybe_unused]] const int _ : std::views::iota(0, m)) {
        int u, v; std::cin >> u >> v, --u, --v;
        to[u].push_back(v);
        to[v].push_back(u);
    }

    std::vector<long> pow(n + 1);
    pow[0] = 1;
    for(const int i : std::views::iota(0, n)) pow[i + 1] = pow[i] * (k + 1);

    lib::leveler<long> level(std::vector<int>(n, k + 1));

    std::vector<std::vector<mint>> dp(level.sup() + 1);
    for(auto& v : dp) v.resize(n);

    for(const int i : std::views::iota(0, n)) dp[pow[i]][i] = 1;

    for(const int x : std::views::iota(0, level.sup())) {
        auto v = level.revert(x) | std::views::reverse;
        // debug(x, v);
        for(const int i : std::views::iota(0, n)) {
            if(v[i] == 0) continue;
            for(const int t : to[i]) {
                if(v[t] == k) continue;
                long nx = x + pow[t];
                // debug(t, level.revert(nx) | std::views::reverse);
                dp[nx][t] += dp[x][i];
            }
        }
    }

    mint ans = 0;

    for(const int i : std::views::iota(0, n)) {
        ans += dp[level.sup() - 1][i];
    }

    std::cout << ans.val() << "\n";
}
