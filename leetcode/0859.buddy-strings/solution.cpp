#include "../../common.hpp"
// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
//  https://leetcode.com/problems/buddy-strings/

struct Solution {
    static bool buddyStrings(const string &s, const string &goal) {
        auto n = s.size();
        if (n != goal.size())
            return false;
        int n_diff = 0;
        size_t diff_pos[2];
        for (size_t i{}; i != n; ++i) {
            if (s[i] != goal[i]) {
                if (n_diff == 2)
                    return false;
                diff_pos[n_diff++] = i;
            }
        }
        if (n_diff == 2) {
            return s[diff_pos[0]] == goal[diff_pos[1]] &&
                   s[diff_pos[1]] == goal[diff_pos[0]];
        }
        if (n_diff == 0) {
            bool visited[26];
            std::fill(visited, visited + 26, false);
            for (char c : s) {
                if (visited[c - 'a'])
                    return true;
                visited[c - 'a'] = true;
            }
            return false;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    TEST(1, s.buddyStrings("ab", "ba"));
    TEST(0, s.buddyStrings("ab", "ab"));
    TEST(1, s.buddyStrings("aa", "aa"));
    return 0;
}
