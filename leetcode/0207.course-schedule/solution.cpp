#include "../../common.hpp"
// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
//  https://leetcode.com/problems/course-schedule/

struct Solution {
  static bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> *requiredBy[numCourses];
    short nChild[numCourses];
    std::fill(requiredBy, requiredBy + numCourses, nullptr);
    std::fill(nChild, nChild + numCourses, 0);

    for (auto &ab : prerequisites) {
      int a = ab[0], b = ab[1];
      vector<int> *&p = requiredBy[b];
      if (p) {
        p->push_back(a);
      } else {
        ab.pop_back();
        p = &ab;
      }
      ++nChild[a];
    }

    std::queue<int> worklist;
    int nHandled = 0;

    auto pop = [&]() {
      ++nHandled;
      int c = worklist.front();
      worklist.pop();
      return c;
    };

    for (int i = 0; i < numCourses; ++i) {
      if (!nChild[i])
        worklist.push(i);
    }

    while (!worklist.empty()) {
      int c = pop();
      auto prerequisites = requiredBy[c];
      if (prerequisites)
        for (int p : *requiredBy[c]) {
          if (--nChild[p] == 0)
            worklist.push(p);
        }
    }

    return nHandled == numCourses;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int>> p1{{1, 0}};
  DEBUG(true, s.canFinish(2, p1));
  vector<vector<int>> p2{{1, 0}, {0, 1}};
  DEBUG(false, s.canFinish(2, p2));
  return 0;
}
