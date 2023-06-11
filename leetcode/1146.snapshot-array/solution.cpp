#include "../../common.hpp"

class SnapshotArray {
  int id;
  vector<vector<std::pair<int, int>>> content;

public:
  SnapshotArray(int length) : id{}, content(length) {}

  void set(int index, int val) {
    auto &ci = content[index];
    if (!ci.empty() && ci.back().first == id) {
      ci.back().second = val;
    } else {
      ci.emplace_back(id, val);
    }
  }

  int snap() { return id++; }

  int get(int index, int snap_id) {
    auto &ci = content[index];
    auto id = std::upper_bound(ci.begin(), ci.end(), snap_id,
                               [](int snap_id, const std::pair<int, int> &p) {
                                 return snap_id < p.first;
                               });
    return id == ci.begin() ? 0 : (--id)->second;
  }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
int main() {
  SnapshotArray a(3);
  a.set(0, 5);
  DEBUG(a.snap());
  a.set(0, 6);
  DEBUG(a.get(0, 0));
}
