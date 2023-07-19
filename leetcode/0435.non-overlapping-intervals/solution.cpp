#include "../../common.hpp"
auto _f{[]() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return nullptr;
}()};
// https://leetcode.com/problems/non-overlapping-intervals

struct Solution {
    static int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end(),
                  [](const vector<int> &v1, const vector<int> &v2) {
                      return v1[1] < v2[1];
                  });
        int t = INT_MIN, keep{};
        for (const auto &v : intervals) {
            if (v[0] >= t) {
                t = v[1];
                ++keep;
            }
        }
        return intervals.size() - keep;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
