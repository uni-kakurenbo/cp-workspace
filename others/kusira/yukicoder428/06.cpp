/*
 * @uni_kakurenbo
 * https://github.com/uni-kakurenbo/competitive-programming-workspace
 *
 * CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja
 */
/* #language C++ 20 GCC */
#include "template/debug.hpp"

void solve();

signed main() {
    debug(__cplusplus);
    uni::i32 $ = 1;
    // std::cin >> $;
    for(uni::i32 _ = 0; _ < $; ++_) {
        debug_("Case: #" + std::to_string(_));
        solve();
    }
    return 0;
}

#include "numeric/boundary_seeker.hpp"
#include <atcoder/lazysegtree>

uni::i64 e() { return 0; }
uni::i64 op(uni::i64 s, uni::i64 t) { return s + t; }

uni::i64 INF64 = std::numeric_limits<uni::i64>::max() / 2 - 1;

void solve() {
    uni::i32 n; std::cin >> n;
    std::vector<uni::i32> x(n); for(auto& v : x) std::cin >> v;

    std::vector<uni::i32> same(n);
    REP(i, 1, n) same[i] = same[i - 1] + (x[i - 1] == x[i]);

    std::vector<uni::i32> cnt(n + 1);

    uni::i32 q; std::cin >> q;
    REP(q) {
        uni::i32 l, r; uni::i64 s; std::cin >> l >> r >> s; --l;
        debug(l, r, s);

        auto a = x | std::views::take(r) | std::views::drop(l);
        uni::i32 m = r - l;

        if(1L << std::min(m - 1, 62) <= s) {
            std::cout << -1 << "\n";
            continue;
        }

        if(m >= 88) {
            uni::i32 d = same[r - 1] - same[l];
            uni::i64 v = 1L << std::min(d, 62);
            std::cout << uni::i32(v <= s) << "\n";
            continue;
        }

        auto f = [&](uni::i64 k) -> uni::i128 {
            if(k == 0) return 0;

            std::vector<uni::i32> max_right(m);
            {
                uni::i32 j = 0;

                uni::i32 kinds = 0;

                REP(i, m) {
                    while(j < m) {
                        if(cnt[a[j++]]++ == 0) ++kinds;
                        if(kinds > k) {
                            --j;
                            if(--cnt[a[j]] == 0) --kinds;
                            break;
                        }
                    }
                    max_right[i] = j;
                    if(--cnt[a[i]] == 0) --kinds;
                }
                debug(max_right, cnt);
            }

            atcoder::lazy_segtree<long, op, e, long, op, op, e> dp(m + 1);
            dp.set(0, 1);
            REP(i, m) {
                if(dp.get(i) > s) return uni::INF64;
                dp.apply(i + 1, max_right[i] + 1, dp.get(i));
            }
            debug(k, dp);

            return dp.get(m);
        };

        uni::boundary_seeker<long> seeker([&](long k){ return f(k) <= s; });
        std::cout << seeker.bound(0, m + 1) << "\n";
    }
}
