#include <iostream>
#include <vector>
#include <queue>

int main() {
    int h, w; std::cin >> h >> w;
    std::vector<std::vector<int>> a(h);
    for(auto& row : a) {
        row.resize(w);
        for(auto& v : row) std::cin >> v;
    }

    using P = std::pair<int, std::pair<int, int>>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> que[2];
    que[0].emplace(a[0][1], std::make_pair(0, 1));
    que[0].emplace(a[1][0], std::make_pair(1, 0));
    que[1].emplace(a[h - 1][w - 2], std::make_pair(h - 1, w - 2));
    que[1].emplace(a[h - 2][w - 1], std::make_pair(h - 2, w - 1));

    std::vector<std::vector<int>> color(h);
    for(auto& row : color) {
        row.resize(w, -1);
    }
    color[0][0] = 0;
    color[h - 1][w - 1] = 1;

    for(int t = 0; ;) {
        auto& cands = que[t % 2];
        auto [ _, p ] = cands.top(); cands.pop();
        auto [ i, j ] = p;
        if(color[i][j] >= 0) continue;

        color[i][j] = t % 2;
        // std::cerr << t << " " << i << " " << j << "\n";

        constexpr std::pair<int, int> DIRS[] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

        for(const auto& [ di, dj ] : DIRS) {
            if(i + di >= h || i + di < 0) continue;
            if(j + dj >= w || j + dj < 0) continue;

            if(color[i + di][j + dj] == ((t + 1) % 2)) {
                std::cout << t + 1 << "\n";
                return 0;
            }

            if(color[i + di][j + dj] == -1) {
                // std::cerr << i + di << " " << j + dj << "\n";
                cands.emplace(a[i + di][j + dj], std::make_pair(i + di, j + dj));
            }
        }

        ++t;
    }
}
