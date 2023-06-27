#include "../../common.hpp"
auto fastio{[]() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  return nullptr;
}()};
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
struct Solution {
  using VI = vector<int>;
  using VVI = vector<VI>;
  using PII = std::pair<int, int>;
  static VVI kSmallestPairs(VI const &nums1, VI const &nums2, int k) {
    VVI result;
    result.reserve(k);
    auto comp = [&](PII p1, PII p2) {
      return nums1[p1.first] + nums2[p1.second] >
             nums1[p2.first] + nums2[p2.second];
    };
    std::priority_queue<PII, vector<PII>, decltype(comp)> q(comp);
    q.push({0, 0});
    // auto print = [&](const char *p = "", PII *b = 0) {
    //   printf("    %s: %d x ", p, buf_end);
    //   for (int i = 0; i < buf_end; ++i) {
    //     auto [x, y] = b[i];
    //     printf("(%d)%d,%d\t", nums1[x] + nums2[y], nums1[x],
    //            nums2[y]); //, x, y);
    //   }
    //   printf("\n");
    // };
    std::unordered_set<uint64_t> visited;
    while (!q.empty()) {

      // print("PoPBuf0", buf);
      auto [x, y] = q.top();
      q.pop();

      printf("getting (%d,%d)\n", nums1[x], nums2[y]);
      result.push_back({nums1[x], nums2[y]});

      if (result.size() == k)
        break;

      if (x + 1u < nums1.size() &&
          visited.insert(((uint64_t)x + 1) << 18 | y).second) {
        // buf[buf_end++] = {x + 1, y};
        // std::push_heap(buf, buf + buf_end, comp);
        q.push({x + 1, y});

        printf("  push (%d,%d)\n", nums1[x + 1], nums2[y]);
      }
      // print("P1 Buf ", buf);

      if (y + 1u < nums2.size() &&
          visited.insert((uint64_t)x << 18 | y + 1).second) {
        // buf[buf_end++] = {x, y + 1};
        // std::push_heap(buf, buf + buf_end, comp);
        q.push({x, y + 1});
        printf("  push (%d,%d)\n", nums1[x], nums2[y + 1]);
      }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  // DEBUG(Solution::kSmallestPairs({1, 7, 11}, {2, 4, 6}, 3));
  // DEBUG(Solution::kSmallestPairs({1, 1, 2}, {1, 2, 3}, 2));
  // DEBUG(Solution::kSmallestPairs({1, 2}, {3}, 3));
  DEBUG(Solution::kSmallestPairs({1, 7, 11}, {2, 4, 6}, 100));
  return 0;
}
