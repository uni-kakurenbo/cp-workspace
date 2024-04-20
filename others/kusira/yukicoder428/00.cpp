#include <iostream>
#include <vector>
#include <string>
#include <ranges>

signed main() {
    int n, k; std::cin >> n >> k;
    std::vector<std::string> a(n);
    for(auto& row : a) std::cin >> row;

    const auto rk = std::views::iota(0, k);

    for(const auto& row : a) {
        for([[maybe_unused]] const int _ : rk) {
            for(const auto v : row) {
                for([[maybe_unused]] const int _ : rk) std::cout << v;
            }
            std::cout << "\n";
        }
    }
}
