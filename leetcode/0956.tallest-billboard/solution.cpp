#include "../../common.hpp"
auto fastio{[]() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  return nullptr;
}()};

// https://leetcode.com/problems/tallest-billboard/
struct Solution {
  static int tallestBillboard(vector<int> &rods) {
    int sum{std::reduce(rods.begin(), rods.end())};
    size_t n_elem = sum + 1, size{sizeof(uint16_t) * n_elem};
    uint16_t d2h[2 * n_elem]; // 15 bit + 1 bit
    uint16_t *last{d2h}, *current{d2h + n_elem};
    memset(last, 0, size);
    last[0] = 1;
    auto update = [](uint16_t &oldh, uint16_t newh) {
      oldh = std::max(oldh, (uint16_t)(1 | newh << 1));
    };
    for (int n : rods) {
      memcpy(current, last, size);
      for (size_t d = 0; d < n_elem; ++d) {
        if (!(last[d] & 1))
          continue;
        int h = last[d] >> 1;
        update(current[d + n], h + n);
        if (int newd = (int)d - n; newd >= 0)
          update(current[newd], h);
        else
          update(current[-newd], h - newd);
      }
      std::swap(last, current);
    }
    return last[0] >> 1;
  }
};

int main(int argc, char *argv[]) {
  vector<int> vs[] = {{1, 2, 3, 6}, {1, 2, 3, 4, 5, 6}, {1, 2}};
  Solution s;
  for (auto &v : vs) {
    int n = s.tallestBillboard(v);
    // DEBUG(v, n, "\n");
  }
  return 0;
}
