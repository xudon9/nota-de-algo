#include "../../common.hpp"
// auto fastio{[]() { std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
// https://leetcode.com/problems/last-day-where-you-can-still-cross/
struct Info {
  int parent;
  int height;
};

void initDsu(Info buf[], int size) {
  for (int i = 0; i < size; ++i) {
    buf[i] = {i, 1};
  }
}

int getRepr(Info buf[], int id) {
  int p;
  while ((p = buf[id].parent) != id)
    id = p;
  return id;
}

int join(Info buf[], int i1, int i2) {
  if (i1 == i2)
    return i1;
  int r1{getRepr(buf, i1)}, r2{getRepr(buf, i2)};
  int &h1{buf[r1].height}, &h2{buf[r2].height};
  if (h1 <= h2) {
    h2 = std::max(h2, 1 + h1);
    return buf[r1].parent = r2;
  } else {
    h1 = std::max(h1, 1 + h2);
    return buf[r2].parent = r1;
  }
}

struct Solution {
  int latestDayToCross(int row, int col, const vector<vector<int>> &cells) {
    assert(cells.size() == row * col);

    int n = row * col;
    Info dsu[n + 2];
    initDsu(dsu, n + 2);
    bool water[row][col];
    memset(water, 0, sizeof(water));
    const int8_t dirs[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                              {0, 1},   {1, -1}, {1, 0},  {1, 1}};
    int day = 0;
    for (auto &pair : cells) {
      int y{pair[0] - 1}, x{pair[1] - 1};
      water[y][x] = true;

      cout << "\nday = " << day + 1 << "\n";
      for (int j = 0; j < row; ++j) {
        std::printf("%3d", col * (1 + j));
      }
      puts("");
      for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
          cout << (water[j][i] ? "  ." : "  #");
        }
        cout << '\n';
      }

      int yx = y * col + x + 2;
      DEBUG(yx);
      for (auto [dy, dx] : dirs) {
        int i{y + dy}, j{x + dx};
        if (0 <= i && i < row && 0 <= j && j < col && water[i][j]) {
          int n = join(dsu, yx, i * col + j + 2);
          printf("mg %d -> %d as %d\n", yx, i * col + j + 2, n);
        }
      }

      if (!x) {
        puts("jl"), join(dsu, yx, 0);
      }
      DEBUG(getRepr(dsu, yx), getRepr(dsu, 0), getRepr(dsu, 1));
      int right =
          x + 1 == col ? (puts("jr"), join(dsu, yx, 1)) : getRepr(dsu, 1);
      DEBUG(getRepr(dsu, yx), getRepr(dsu, 0), getRepr(dsu, 1));
      // Left might be changed
      if (getRepr(dsu, 0) == right)
        return day;
      ++day;
    }
    return n;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  TEST(2, s.latestDayToCross(2, 2, {{1, 1}, {2, 1}, {1, 2}, {2, 2}}));
  TEST(1, s.latestDayToCross(2, 2, {{1, 1}, {1, 2}, {2, 1}, {2, 2}}));
  TEST(3, s.latestDayToCross(3, 3,
                             {{1, 2},
                              {2, 1},
                              {3, 3},
                              {2, 2},
                              {1, 1},
                              {1, 3},
                              {2, 3},
                              {3, 2},
                              {3, 1}}));
  vector<vector<int>> v{
      {39, 2}, {2, 2},  {4, 1},  {25, 1}, {30, 2}, {8, 2},  {27, 1}, {16, 1},
      {15, 1}, {42, 2}, {13, 1}, {35, 1}, {40, 2}, {33, 2}, {36, 2}, {32, 2},
      {24, 2}, {17, 1}, {35, 2}, {28, 2}, {24, 1}, {38, 2}, {16, 2}, {40, 1},
      {23, 2}, {45, 1}, {34, 2}, {26, 1}, {26, 2}, {28, 1}, {10, 1}, {18, 1},
      {36, 1}, {21, 1}, {22, 1}, {1, 1},  {43, 1}, {37, 2}, {20, 1}, {34, 1},
      {39, 1}, {5, 2},  {42, 1}, {41, 2}, {5, 1},  {3, 2},  {9, 1},  {12, 1},
      {13, 2}, {7, 1},  {9, 2},  {14, 2}, {44, 1}, {3, 1},  {15, 2}, {12, 2},
      {31, 1}, {6, 1},  {8, 1},  {29, 1}, {29, 2}, {22, 2}, {19, 2}, {10, 2},
      {32, 1}, {37, 1}, {38, 1}, {43, 2}, {21, 2}, {1, 2},  {27, 2}, {11, 1},
      {20, 2}, {11, 2}, {7, 2},  {30, 1}, {2, 1},  {23, 1}, {41, 1}, {17, 2},
      {18, 2}, {25, 2}, {31, 2}, {33, 1}, {4, 2},  {45, 2}, {44, 2}, {6, 2},
      {19, 1}, {14, 1}};
  TEST(14, s.latestDayToCross(45, 2, v));
  return 0;
}
