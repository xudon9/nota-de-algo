#include "../../common.hpp"
auto fastio{[]() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  return nullptr;
}()};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
struct Solution {
  static int maxProfit(const vector<int> &prices, int fee) {
    auto it = prices.cbegin(), ite = prices.cend();
    int best0{}, best1{-*it++};
    for (; it != ite; ++it) {
      int nbest0 = std::max(best0, best1 + *it - fee);
      int nbest1 = std::max(best1, best0 - *it);
      best0 = nbest0;
      best1 = nbest1;
    }
    return best0;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v{1, 3, 2, 8, 4, 9};
  int fee = 2;
  std::cout << Solution::maxProfit(v, fee) << "\n";
  return 0;
}
