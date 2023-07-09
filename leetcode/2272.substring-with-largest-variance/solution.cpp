#include "../../common.hpp"
#include <numeric>
// REVISIT
// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
//  https://leetcode.com/problems/substring-with-largest-variance/

vector<int> generateRandomString(int len = 80, int min = -100, int max = 100) {
  int n = max - min;
  std::vector<int> v(len, 0);
  for (auto &e : v) {
    e = min + rand() % n;
  }
  return v;
}

int kadaneSum(const vector<int> &arr) {
  int prevMax = 0, ret = 0;
  for (auto e : arr) {
    prevMax = std::max(prevMax, 0) + e;
    DEBUG(prevMax);
    ret = std::max(prevMax, ret);
  }
  return ret;
}

int kadaneSumSpec(const vector<int> &arr) {
  int ret = 0;
  for (int i = 0; i < arr.size(); ++i) {
    int sum = arr[i], local = arr[i];
    for (int j = i - 1; j >= 0; --j) {
      sum += arr[j];
      local = std::max(local, sum);
    }
    DEBUG(local);
    ret = std::max(ret, local);
  }
  return ret;
}

struct Solution {
#define N 26
  static int kadane(const string &s, char c1, char c2, int n2) {
    int ret{}, cnt1{}, cnt2{};
    for (char c : s) {
      cnt1 += (c == c1);
      cnt2 += (c == c2);
      n2 -= (c == c2);
      int score = cnt1 - cnt2;
      if (cnt2)
        ret = std::max(ret, score);
      // prevMax = std::max(prevMax, 0) + (c == c1) - (c == c2);
      if (score < 0 && n2) {
        cnt1 = cnt2 = 0;
      }
    }
    return ret;
  }

  static int largestVariance(const string &s) {
    int cnt[N];
    std::fill(cnt, cnt + N, 0);

    for (auto c : s) {
      ++cnt[c - 'a'];
    }

    int ret{};

    for (int i = 0; i < N; ++i) {
      if (!cnt[i])
        continue;
      for (int j = 0; j < N; ++j) {
        if (i == j || !cnt[j])
          continue;
        ret = std::max(kadane(s, 'a' + i, 'a' + j, cnt[j]), ret);
      }
    }

    return ret;
  }
};

int main(int argc, char *argv[]) {
  // for (int i = 0; i < 10; ++i) {
  //     auto v = generateRandomString(500);
  //     TEST(kadaneSum(v), kadaneSumSpec(v));
  // }

  Solution s;
  TEST(s.largestVariance("aababbb"), 3);
  TEST(s.largestVariance("abcde"), 0);
  return 0;
}
