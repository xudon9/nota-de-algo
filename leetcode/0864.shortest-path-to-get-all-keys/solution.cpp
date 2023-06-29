#include "../../common.hpp"
// auto fastio{[]() {
//   std::ios::sync_with_stdio(0);
//   std::cin.tie(0);
//   return nullptr;
// }()};

// https://leetcode.com/problems/shortest-path-to-get-all-keys/description/
struct Solution {
  using Pos = std::pair<int8_t, int8_t>;
  using KeySet = uint8_t;
  struct State {
    int length;
    Pos pos;
    KeySet keys;
  };

  std::pair<Pos, KeySet> findStartAndCountKeys(vector<string> const &grid) {
    Pos startLoc{};
    KeySet k = 0;
    int8_t i{};
    for (auto &row : grid) {
      int8_t j{};
      for (char c : row) {
        if (c == '@')
          startLoc = {i, j};
        else if (auto d = c - 'a'; 0 <= d && d < 6)
          k |= (1 << d);
        ++j;
      }
      ++i;
    }
    return {startLoc, k};
  }

  int shortestPathAllKeys(vector<string> const &grid) {
    vector<std::pair<uint8_t, char>> v(10, {'x', 'y'});
    const Pos dirs[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int8_t n_row = grid.size(), n_col = grid[0].size();
    std::bitset<1 << 6> visited[n_row][n_col];
    std::memset(visited, 0, sizeof(visited));
    std::queue<State> q;
    auto [start, allKey] = findStartAndCountKeys(grid);
    q.push({0, start, 0});

    while (!q.empty()) {
      auto [len, pos, keys] = q.front();
      q.pop();
      if (allKey == keys)
        return len;
      for (auto dpos : dirs) {
        auto newk{keys};
        Pos p{pos.first + dpos.first, pos.second + dpos.second};
        if (p.first < 0 || n_row <= p.first || p.second < 0 ||
            n_col <= p.second)
          continue;
        char ch{grid[p.first][p.second]};
        if (ch == '#')
          continue;
        if (auto d = ch - 'A'; 0 <= d && d < 6 && !(keys & (1 << d)))
          continue;
        if (auto d = ch - 'a'; 0 <= d && d < 6)
          newk |= (1 << d);
        if (visited[p.first][p.second].test(newk))
          continue;
        visited[p.first][p.second].set(newk);
        q.push({len + 1, p, newk});
      }
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  // TEST(8, s.shortestPathAllKeys({"@.a..", "###.#", "b.A.B."}));
  // TEST(6, s.shortestPathAllKeys({"@..aA", "..B#.", "....b"}));
  // TEST(-1, s.shortestPathAllKeys({"@Aa"}));
  // TEST(1, s.shortestPathAllKeys({"@aA"}));
  TEST(7, s.shortestPathAllKeys({"...#.", "a..@.", "#..#.", "b.#B.", ".##.A"}));
  return 0;
}
