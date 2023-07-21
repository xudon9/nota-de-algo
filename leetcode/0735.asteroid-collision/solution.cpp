#include "../../common.hpp"
// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
//  https://leetcode.com/problems/asteroid-collision/

struct Solution {
  static vector<int> asteroidCollision(const vector<int> &asteroids) {
    vector<int> stk;
    stk.reserve(asteroids.size());

    for (int i : asteroids) {
      if (stk.size() == 0 || stk.back() < 0 || i > 0) {
        DEBUG(stk.size() == 0 || stk.back() < 0 || i > 0, i);
        stk.push_back(i);
      } else {
        int absi = std::abs(i);
        while (stk.size() && 0 < stk.back() && stk.back() < absi) {
          stk.pop_back();
        }
        if (stk.size() == 0 || stk.back() < 0) {
          stk.push_back(i);
        } else if (stk.back() == absi) {
          stk.pop_back();
        }
      }
    }
    return stk;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  TEST((vector<int>{5, 10}), s.asteroidCollision({5, 10, -5}));
  TEST((vector<int>{}), s.asteroidCollision({8, -8}));
  TEST((vector<int>{10}), s.asteroidCollision({10, 2, -5}));
  return 0;
}
