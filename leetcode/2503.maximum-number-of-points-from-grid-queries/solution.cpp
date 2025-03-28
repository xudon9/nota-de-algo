#if 0
c++ "$@" -DLOCAL_DBG -fsanitize=undefined,address -std=c++17 "$0" && exec ./a.out || exit
#endif
// #define LOCAL_DBG 1

#if LOCAL_DBG
#  include "../../cxx-common/common.hpp"
#else
#  define DEBUG(...) /* Nothing */
#endif

/* Paste LeetCode template here */
struct Solution {
  using Pos = pair<short, short>;
  static vector<int> maxPoints(const vector<vector<int>> &grid,
                               const vector<int> &queries) {
    auto gAt = [&](Pos p) -> int { return grid[p.first][p.second]; };
    auto posGt = [&](Pos p1, Pos p2) { return gAt(p1) > gAt(p2); };
    priority_queue<Pos, vector<Pos>, decltype(posGt)> wl(posGt);
    vector<vector<uint8_t>> visited(grid.size(),
                                    vector<uint8_t>(grid[0].size(), false));
    auto vAt = [&](Pos p) -> uint8_t & { return visited[p.first][p.second]; };
    auto pGo = [&](Pos p, Pos d) -> pair<bool, Pos> {
      int y{p.first + d.first}, x{p.second + d.second};
      bool valid = 0 <= y && y < grid.size() && 0 <= x && x < grid[0].size();
      return {valid, {y, x}};
    };

    std::vector<pair<int, int>> val2cnt;
    Pos initPos{0, 0};
    wl.emplace(initPos);
    vAt(initPos) = true;
    int nVisited{}, curMax{gAt(initPos)};

    while (!wl.empty()) {
      auto p = wl.top();
      DEBUG(p);
      wl.pop();

      int curVal{gAt(p)};
      if (curVal > curMax) {
        val2cnt.emplace_back(curMax, nVisited);
        curMax = curVal;
      }

      ++nVisited;

      Pos ds[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
      for (Pos d : ds) {
        auto [valid, d2] = pGo(p, d);
        if (valid && !vAt(d2)) {
          vAt(d2) = 1;
          wl.emplace(d2);
        }
      }
    }
    val2cnt.emplace_back(curMax, nVisited);

    DEBUG(val2cnt);

    std::vector<int> result;
    result.reserve(queries.size());

    for (int q : queries) {
      auto it =
          std::lower_bound(val2cnt.begin(), val2cnt.end(), make_pair(q, 0));
      int n = it == val2cnt.begin() ? 0 : (--it)->second;
      result.push_back(n);
    }

    return result;
  }
};

#if LOCAL_DBG
int main(int argc, char *argv[]) {
  // TEST_MASK = TEST_BIT(0) | TEST_BIT(2);

  // TEST_BLK_A {
  //   Solution s;
  //   int n = 0;
  //   vector<int> input1 = "[1,2,3,4]"_json;
  //   vector<vector<int>> input2 = "[[1,2],[3,4]]"_json;
  //   TEST(s.foo(n, input1, input2), 42);
  // }

  TEST_EQ_A(Solution::maxPoints("[[1,2,3],[2,5,7],[3,5,1]]"_json, {5, 6, 2}),
            vector({5, 8, 1}));
  TEST_EQ_A(Solution::maxPoints("[[5,2,1],[1,1,2]]"_json, {3}), vector({0}));
}
#endif
