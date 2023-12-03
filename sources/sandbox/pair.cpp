/*
 * @uni_kakurenbo
 * https://github.com/uni-kakurenbo/competitive-programming-workspace
 *
 * CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja
 */
/* #language C++ 20 GCC */
// #include "template/standard.hpp"
#include "template/debug.hpp"
#include <concepts>

void solve();

signed main() {
    debug(__cplusplus);
    int $ = 1;
    // std::cin >> $;
    for(int _ = 0; _ < $; ++_) {
        DEBUG("Case: #" + std::to_string(_));
        solve();
    }
    return 0;
}


template<class T0, class T1>
struct pair {
    using first_type = T0;
    using second_type = T1;

    first_type first;
    second_type second;

    pair() = default;
    pair(const first_type& v0, const second_type& v1) : first(v0), second(v1) {}

    inline pair rorated() const
        requires std::integral<first_type> && std::integral<second_type>
    {
        return pair<second_type,first_type>(-this->second, this->first);
    }
};

void solve() {

}
