// #define LOCAL_DBG 1

#include <algorithm>
#if LOCAL_DBG
#  include "../../cxx-common/common.hpp"
#else
#  define DEBUG(...) /* Nothing */
#endif

/* Paste LeetCode template here */
#define START 0
#define END 1
#define IS_BEG(x) (!IS_END(x))
#define IS_END(x) ((x) & 1u)
#define DATE(x) ((x) / 2)

struct Solution {
  static int countDays(int days, const vector<vector<int>> &meetings) {
    vector<unsigned> tasks;
    for (auto &meeting : meetings) {
      int daybeg = 2 * meeting[0], dayend = 2 * meeting[1] + 1;
      auto it = std::upper_bound(tasks.begin(), tasks.end(), daybeg);
      auto idx = it - tasks.begin();
      // if (IS_BEG(*it)) {
      //   // TODO
      // } else {
      // }
    }
    return 0;
  }
};

#if LOCAL_DBG
int main(int argc, char *argv[]) {
  // int TEST_MASK = TEST_BIT(2) | TEST_BIT(2);
  Solution s;
  unsigned x = 0;
  --x;

  TEST_EQ_A((s.countDays(10, "[[5,7],[1,3],[9,10]]"_json)), 2)
  TEST_EQ_A((s.countDays(5, "[[2,4],[1,3]]"_json)), 1)
  TEST_EQ_A((s.countDays(6, "[[1,6]]"_json)), 0)

  // TEST_EQ_0(0, 0);

  return 0;
}
#endif
