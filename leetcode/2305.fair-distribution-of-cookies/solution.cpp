#include "../../common.hpp"
#include <functional>
// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
//  https://leetcode.com/problems/fair-distribution-of-cookies/
struct Solution {
    int const *cookies;
    int k, min, *buf, len, avg;

    void go(int i) {
        if (i == len) {
            min = std::min(min, *std::max_element(buf, buf + k));
        } else {
            int amount = cookies[i];
            for (int j = 0; j < k; ++j) {
                if (buf[j] <= avg && (!j || buf[j] != buf[j - 1]) &&
                    buf[j] + amount < min) {
                    buf[j] += amount;
                    go(i + 1);
                    buf[j] -= amount;
                }
            }
        }
    }

    int distributeCookies(const vector<int> &cookies, int k) {
        int buf[k];
        std::memset(buf, 0, sizeof(buf));

        this->buf = buf;
        this->k = k;
        this->min = INT_MAX;
        this->cookies = cookies.data();
        this->len = cookies.size();
        this->avg = std::reduce(cookies.begin(), cookies.end(), 0) / k;

        go(0);

        return min;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    TEST(s.distributeCookies({8, 15, 10, 20, 8}, 2), 31);
    TEST(s.distributeCookies({6, 1, 3, 2, 2, 4, 1, 2}, 3), 7);
}
