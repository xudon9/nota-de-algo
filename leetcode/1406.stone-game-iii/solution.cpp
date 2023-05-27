#include "../../common.hpp"

// URL: https://leetcode.com/problems/stone-game-iii/description/

template <class T, unsigned N> class FixedQueue {
private:
  T buffer[N];
  unsigned i;

public:
  FixedQueue() : i(0) {}

  T &back(unsigned n = 1) { return buffer[(i + N - n) % N]; }

  void put(const T &value) {
    buffer[i] = value;
    i = (i + 1) % N;
  }
};

class Solution {
  using Score = std::pair<int, int>;

  static Score add(Score c, int n) { return {c.second + n, c.first}; }
  static string winner(Score c) {
    auto [alice, bob] = c;
    return alice > bob ? "Alice" : (alice == bob ? "Tie" : "Bob");
  }

public:
  static string stoneGameIII(vector<int> &stoneValue) {
    FixedQueue<Score, 3> q;

    auto it = stoneValue.crbegin(), end = stoneValue.crend();
    int b1 = *it++;

    // Last one
    q.put({b1, 0});

    // Last two
    if (it == end)
      return winner(q.back());
    int b2 = *it++;
    {
      Score take1{b2, b1};
      Score take2{b2 + b1, 0};
      q.put(std::max(take1, take2));
    }

    // Last three
    if (it == end)
      return winner(q.back());
    int b3 = *it++;
    {
      Score take1 = add(q.back(1), b3);
      Score take2{b3 + b2, b1};
      Score take3{b3 + b2 + b1, 0};
      q.put(std::max({take1, take2, take3}));
    }

    for (; it != stoneValue.crend(); ++it) {
      int sum = 0;
      Score take1 = add(q.back(1), sum += *(it - 0));
      Score take2 = add(q.back(2), sum += *(it - 1));
      Score take3 = add(q.back(3), sum += *(it - 2));
      Score best = std::max({take1, take2, take3});
      // DEBUG(best, take1, take2, take3);
      q.put(best);
    }
    return winner(q.back());
  }
};

int main() {
  vector<int> values = {-1, -2, -3};
  auto s = Solution::stoneGameIII(values);
  DEBUG(s);
}
