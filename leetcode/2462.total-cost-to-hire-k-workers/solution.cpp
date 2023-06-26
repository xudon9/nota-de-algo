#include "../../common.hpp"
auto fastio{[]() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  return nullptr;
}()};
// https://leetcode.com/problems/total-cost-to-hire-k-workers/description/

struct Solution {
  static int64_t totalCost(const vector<int> &costs, int k, const int n) {
    auto comp = [&costs](unsigned i, unsigned j) {
      return std::make_pair(costs[i], i) > std::make_pair(costs[j], j);
    };
    unsigned buf[2 * n];
    const int cost_len = costs.size();
    // n <= cost.len, no need to check
    std::iota(buf, buf + n, 0);
    // Note: nextL is unused, but (nextR-1) is unused!
    int nextL{n}, nextR{std::max(cost_len - n, n)};
    const int lenR = cost_len - nextR;
    int buf_end = n + lenR;
    std::iota(buf + n, buf + buf_end, nextR);

    std::make_heap(buf, buf + buf_end, comp);
    for (int64_t cost_sum{};;) {
      std::pop_heap(buf, buf + buf_end, comp);
      unsigned index = buf[--buf_end];
      DEBUG(index, costs[index]);
      cost_sum += costs[index];
      if (!--k)
        return cost_sum;
      if (nextL < nextR) {
        buf[buf_end++] = index < nextL ? nextL++ : --nextR;
        std::push_heap(buf, buf + buf_end, comp);
      }
    }
  }
  static int64_t totalCost2(const vector<int> &costlist, int k, const int n) {
    vector<std::pair<int, int>> costs;
    for (int i = 0; i < (int)costlist.size(); ++i) {
      costs.push_back({costlist[i], i});
    }

    int64_t cost_sum{};
    while (k--) {
      int mi = 0;
      int end = (int)costs.size();
      for (auto i = 0; i < std::min(n, end); ++i) {
        if (costs[i].first < costs[mi].first)
          mi = i;
      }
      for (auto i = std::max(end - n, 0); i < end; ++i) {
        if (costs[i].first < costs[mi].first)
          mi = i;
      }
      printf("2 choose [%d] %d\n", costs[mi].second, costs[mi].first);
      cost_sum += costs[mi].first;
      costs.erase(costs.begin() + mi);
    }
    return cost_sum;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  TEST(s.totalCost({17, 12, 10, 2, 7, 2, 11, 20, 8}, 3, 4), 11);
  TEST(s.totalCost({1, 2, 4, 1}, 3, 3), 4);
  TEST(s.totalCost({8, 5, 10, 1, 8}, 2, 1), 5 + 8);
  vector<int> costs{31, 25, 72, 79, 74, 65, 84, 91,
                    18, 59, 27, 9,  81, 33, 17, 58};
  DEBUG(costs);
  TEST(s.totalCost(costs, 11, 2), 423);
  puts("");
  TEST(s.totalCost2(costs, 11, 2), 423);
  return 0;
}
