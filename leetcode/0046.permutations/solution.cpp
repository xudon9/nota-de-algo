#include "../../common.hpp"
#include <cstdint>
auto fastio{[]() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return nullptr;
}()};
// https://leetcode.com/problems/permutations/

class Solution {
  public:
    static void go(vector<vector<int>> &r, vector<int> &p,
                   const vector<int> &nums, uint8_t mask) {
        if (p.size() == nums.size())
            r.push_back(p);

        for (int i = 0; i < nums.size(); ++i) {
            if ((mask >> i) & 0x1)
                continue;
            p.push_back(nums[i]);
            uint8_t mask2 = mask | (0x1 << i);
            go(r, p, nums, mask2);
            p.pop_back();
        }
    }

    static vector<vector<int>> permute(const vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> p;
        p.reserve(nums.size());
        go(result, p, nums, 0);
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    DEBUG(s.permute({1, 2, 3}));
    DEBUG(s.permute({0, 1}));
    return 0;
}
