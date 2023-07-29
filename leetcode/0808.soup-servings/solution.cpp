#include "../../common.hpp"
// nullptr; }()};
//  https://leetcode.com/problems/soup-servings/

std::map<std::pair<int, int>, double> dp;

double go(int a, int b) {
    if (a <= 0) {
        return b <= 0 ? .5 : 1;
    }
    if (b <= 0)
        return 0;
    auto [it, inserted] = dp.emplace(std::make_pair(a, b), 0);
    if (inserted) {
        double p = (go(a - 4, b) + go(a - 3, b - 1) + go(a - 2, b - 2) +
                    go(a - 1, b - 3)) /
                   4;
        it->second = p;
    }
    return it->second;
}

std::vector<double> answer = []() {
    std::vector<double> r;
    r.reserve(230);

    for (int i = 0;; ++i) {
        double p = go(i, i);
        if (1 - p < 1e-6)
            break;
        r.push_back(p);
    }

    return r;
}();

struct Solution {
    static double soupServings(int n) {
        int i = n / 25 + (bool)(n % 25);
        return i < answer.size() ? answer[i] : 1;
    }
};

int main(int argc, char *argv[]) {
    Solution s;

    for (int i = 0; i < answer.size(); ++i) {
        std::cout << answer[i] << ",\n";
    }

    // TEST(0.625, s.soupServings(50));
    // TEST(0.71875, s.soupServings(100));
    return 0;
}
