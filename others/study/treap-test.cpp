/*
 * @uni_kakurenbo
 * https://github.com/uni-kakurenbo/competitive-programming-workspace
 *
 * CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja
 */
/* #language C++ 20 GCC */
// #define DEBUGGER_ENABLED

#include "template/standard.hpp"

void solve();

signed main() {
    debug(__cplusplus);
    int $ = 1;
    // std::cin >> $;
    for(int _ = 0; _ < $; ++_) {
        debug_("Case: #" + std::to_string(_));
        solve();
    }
    return 0;
}

#include "data_structure/dynamic_sequence.hpp"
#include "data_structure/red_black_tree.hpp"

#include "template/warnings.hpp"
void solve() {
    uni::dynamic_sequence<uni::i32> tree(10000, 0);
    REP(i, 1, 5000, 2) {
        tree(i, tree.size() - i) = i;
    }

    debug(tree.dump_rich());
    debug(tree.size());

    // using Core = uni::dynamic_sequence<uni::i32>::sequence_core;

    // Core core;

    // auto t0 = Core::node_handler::nil;

    // REP(i, 100) {
    //     core.insert(t0, t0->size, i, 10);
    // }

    // debug(core.dump_rich(t0));

    // Core::node_pointer t1, t2;
    // core.split(t0, 45, t1, t2);
    // debug(core.dump_rich(t1), core.dump_rich(t2));
}
