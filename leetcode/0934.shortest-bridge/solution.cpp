#include "../../common.hpp"

// https://leetcode.com/problems/shortest-bridge/

#include <cassert>
#include <set>

typedef vector<vector<int>> Grid;
typedef std::pair<int, int> Loc;
typedef std::set<Loc> LocSet;

inline int &grid_at(Grid &grid, Loc loc) { return grid[loc.first][loc.second]; }
inline bool loc_vaid(Loc loc, int n) {
  auto [x, y] = loc;
  return 0 <= x && x < n && 0 <= y && y < n;
}

Loc first_island_cell(Grid &grid) {
  const int n = grid.size();
  // Find an island cell
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j]) {
        return {i, j};
      }
    }
  }
  assert(false);
}

void find_connected_island(Grid &grid, LocSet &handled, Loc loc) {
  auto [x, y] = loc;
  const int n = grid.size();

  Loc locs[4] = {{x-1,y}, {x+1,y}, {x,y-1}, {x,y+1}};
  for (Loc nl : locs) {
    if (!loc_vaid(nl)) continue;
    if (grid_at(grid, nl) == 0) continue;
    auto inserted = handled.emplace(nl);
    if (!inserted) continue;

  }
}

int shortest_path(Grid &grid) {
  Loc cell = first_island_cell(grid);

  std::set<Loc> handled;
}
