#include <bits/stdc++.h>
using namespace std;

class Solution {
    using Key = std::pair<uint8_t, uint8_t>;
    using Val = std::pair<int, int>;

    map<Key, Val> cache;
    vector<int> arr;

    Val go(Key key) {
        auto [it, ite] = cache.equal_range(key);
        if (it != ite)
            return it->second;
        auto [idx, m] = key;
        Val opt {0, 0};
        int s = 0;
        uint8_t i = 0, lim = std::min(2*m, (uint8_t)arr.size() - idx);
        while (i < lim) {
            s += arr[idx + i];
            ++i;
            auto [other, me] = go({idx + i, max(m, i)});
            opt = max(opt, make_pair(me + s, other));
        }
        cache.emplace_hint(it, key, opt);
        return opt;
    }

public:
    int stoneGameII(vector<int>& piles) {
        cache.clear();
        arr = std::move(piles);
        return go({0, 1}).first;
    }
};
