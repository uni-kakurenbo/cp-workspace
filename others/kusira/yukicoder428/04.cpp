#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <ranges>

int main() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for(auto&  v : a) std::cin >> v;

    auto view = std::views::iota(1, n + 1);
    std::vector<int> ind(std::ranges::begin(view), std::ranges::end(view));

    std::unordered_map<int, int> mp;
    {
        int t = 0;
        do {
            int p = 0;
            for(int i : std::views::iota(0, n)) p ^= a[i] + ind[i];

            if(mp.contains(p)) {
                for(auto& v : ind) std::cout << v << " ";
                std::cout << "\n";

                ind.assign(std::ranges::begin(view), std::ranges::end(view));

                for([[maybe_unused]] const int _ : std::views::iota(0, mp[p])) {
                    std::ranges::next_permutation(ind);
                }

                for(auto& v : ind) std::cout << v << " ";
                std::cout << "\n";

                return 0;
            }
            mp[p] = t++;
        } while(std::ranges::next_permutation(ind).found);
    }


    std::cout << -1 << "\n";
}
