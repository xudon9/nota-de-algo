#include "../../common.hpp"
// https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/

class Solution {
public:
  static int numberOfCuts(int n) { return n == 1 ? 0 : (n & 1 ? n : (n >> 1)); }
};

int main(int argc, char *argv[]) {
  Solution s;
  DEBUG(s.numberOfCuts(5));
  return 0;
}
