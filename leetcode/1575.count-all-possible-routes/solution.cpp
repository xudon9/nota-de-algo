#include "../../common.hpp"
// https://leetcode.com/problems/count-all-possible-routes/

struct Solution {
  uint32_t *dp;
  static const int mod = 1e9 + 7;
  vector<int> locs;
  int finish;

  int go(int src, int fuel) {
    unsigned n = src == finish;
    if (!fuel)
      return n;
    int len = locs.size();
    auto &i = dp[(fuel - 1) * len + src];
    if (i % 2)
      return i >> 1u;
    for (int dst = 0; dst < len; ++dst) {
      if (dst != src)
        if (int rest = fuel - std::abs(locs[src] - locs[dst]); rest >= 0)
          n = (n + go(dst, rest)) % mod;
    }
    i = (n << 1u) | 1u;
    // DEBUG(src, fuel, n);
    return n;
  }

  int countRoutes(vector<int> locations, int st, int fi, int fuel) {
    locs = std::move(locations);
    int n_row = fuel, n_col = locs.size();
    uint32_t buffer[n_row * n_col];
    memset(buffer, 0, sizeof(buffer));
    dp = buffer;
    finish = fi;
    int n = go(st, fuel);
    dumpDp(fuel);
    return n;
  }

  int countRoutesI(vector<int> locations, int st, int finish, int fuel) {
    int n_row = fuel, n_col = locations.size();
    uint32_t dp[n_row * n_col];
    memset(dp, 0, sizeof(dp));
    this->dp = dp;

    for (int f = 1; f <= fuel; ++f) {
      for (int src = 0; src < n_col; ++src) {
        auto &n = dp[(f - 1) * n_col + src];
        n = src == finish;
        for (int dst = 0; dst < n_col; ++dst) {
          if (dst == src)
            continue;
          int rest = f - std::abs(locations[src] - locations[dst]);
          int addent =
              rest > 0 ? dp[(rest - 1) * n_col + dst] : (dst == finish) * !rest;
          n = (n + addent) % mod;
        }
      }
    }
    dumpDp(n_row);
    return dp[(fuel - 1) * n_col + st];
  }

  void dumpDp(int fuel) const {
    printf("F\\Loc");
    for (uint32_t i = 0; i < locs.size(); ++i) {
      char buffer[100];
      snprintf(buffer, sizeof(buffer), "[%d] %d", i, locs[i]);
      printf(" %10s", buffer);
    }
    puts("");
    for (int f = 0; f < fuel; ++f) {
      printf("%5d", 1 + f);
      for (uint32_t i = 0; i < locs.size(); ++i) {
        auto dpi = dp[f * locs.size() + i];
        if (dpi) {
          printf(" %10u", dpi >> 1);
        } else {
          printf(" %10s", "_");
        }
      }
      printf("\n");
    }
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  // DEBUG(s.countRoutes({2, 3, 6, 8, 4}, 1, 3, 5));
  // DEBUG(s.countRoutes({4, 3, 1}, 1, 0, 6));
  // DEBUG(s.countRoutes({5, 2, 1}, 0, 2, 3));
  auto r1 = s.countRoutes({1, 2, 3}, 0, 2, 40);
  auto r2 = s.countRoutesI({1, 2, 3}, 0, 2, 40);
  DEBUG(r1, r2);
  return 0;
}
