#include "../../common.hpp"
// https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst

#define MOD ((int)1e9 + 7)
#define LIMIT 1001

std::array<int, LIMIT> inv;

void initInvTable() {
  inv[0] = 1;
  inv[1] = 1;
  for (int i = 2; i < LIMIT; ++i)
    inv[i] = (MOD - (int64_t)MOD / i) * inv[MOD % i] % MOD;
}

struct Solution {
  static int comb(int total, int n) {
    int64_t r{1};
    int i{}, k{std::min(n, total - n)};
    while (i < k) {
      r = r * total-- % MOD;
      r = r * inv[++i] % MOD;
    }
    return (int)r;
  }

  static int calc(const vector<int> &nums) {
    if (nums.size() <= 2)
      return 1;
    if (inv[0] == 0)
      initInvTable();

    std::vector<int> left, right;
    auto it = nums.cbegin(), ite = nums.cend();
    int pivot = *it++;
    for (; it != ite; ++it) {
      int n = *it;
      (n < pivot ? left : right).push_back(n);
    }
    int64_t n_left{calc(left)}, n_right{calc(right)},
        cnr{comb(nums.size() - 1, left.size())};
    return n_left * n_right % MOD * cnr % MOD;
  }

  static int numOfWays(vector<int> &nums) { return calc(nums) - 1; }
};

int main() {
  std::vector<int> v{3,1,2,5,4,6};
  int n{Solution::numOfWays(v)};
  DEBUG(n);
}
