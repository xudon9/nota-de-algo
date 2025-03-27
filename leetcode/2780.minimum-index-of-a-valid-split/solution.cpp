#if 0
c++ "$@" -DLOCAL_DBG -fsanitize=undefined,address -std=c++17 "$0" && exec ./a.out
#endif

#if LOCAL_DBG
#  include "../../cxx-common/common.hpp"
#else
#  define DEBUG(...) /* Nothing */
#endif

/* Paste LeetCode template here */
template <typename I, typename CI>
void cntMajority(I beg, I end, CI ci, int def) {
  --end;
  std::map<int, int> cnt;
  int n = 0, maj_elem = -100;

  for (I it = beg; it != end; ++it) {
    int cntI = ++cnt[*it];
    if (maj_elem != *it && cntI > cnt[maj_elem]) {
      maj_elem = *it;
    }
    *ci++ = (cnt[maj_elem] > ++n / 2) ? maj_elem : def;
  }
}

struct Solution {
  static int minimumIndex(const vector<int> &nums) {
    DEBUG(nums);
    std::vector<int> majl(nums.size() - 1), majr(nums.size() - 1);
    cntMajority(nums.begin(), nums.end(), majl.begin(), -1);
    cntMajority(nums.rbegin(), nums.rend(), majr.rbegin(), -2);
    DEBUG(majl, majr);
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (majl[i] == majr[i])
        return i;
    }
    return -1;
  }
};

#if LOCAL_DBG
int main(int argc, char *argv[]) {
  // TEST_MASK = TEST_BIT(0) | TEST_BIT(2);

  // TEST_BLK_0 {
  //   Solution s;
  //   int n = 0;
  //   vector<int> input1 = "[1,2,3,4]"_json;
  //   vector<vector<int>> input2 = "[[1,2],[3,4]]"_json;
  //   TEST(s.foo(n, input1, input2), 42);
  // }

  TEST_EQ_A(Solution::minimumIndex("[1,2,2,2]"_json), 2);
  TEST_EQ_A(Solution::minimumIndex("[2,1,3,1,1,1,7,1,2,1]"_json), 4);
  TEST_EQ_A(Solution::minimumIndex("[3,3,3,3,7,2,2]"_json), -1);

  return 0;
}
#endif
