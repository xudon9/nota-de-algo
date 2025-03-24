// #define LOCAL_DBG 1

#if LOCAL_DBG
#  include "../../cxx-common/common.hpp"
#else
#  define DEBUG(...) /* Nothing */
#endif

/* Paste LeetCode template here */

#if LOCAL_DBG
int main(int argc, char *argv[]) {
  // TEST_MASK = TEST_BIT(0) | TEST_BIT(2);

  TEST_BLK_0 {
    Solution s;
    int n = 0;
    vector<int> input1 = "[1,2,3,4]"_json;
    vector<vector<int>> input2 = "[[1,2],[3,4]]"_json;
    TEST(s.foo(n, input1, input2), 42);
  }

  // TEST_EQ_0(0, 0);

  return 0;
}
#endif
