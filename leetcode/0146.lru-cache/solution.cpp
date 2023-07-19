#include "../../common.hpp"
// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
//  https://leetcode.com/problems/lru-cache/description/

using key_t = int;
using val_t = int;
using listIter = std::list<std::pair<key_t, val_t>>::iterator;

class LRUCache {
  private:
    size_t capacity;
    std::map<int, listIter> keymap;
    std::list<std::pair<key_t, val_t>> datalist;

  public:
    LRUCache(int c) : capacity(c) {}

    val_t get(key_t key) {
        auto iter = keymap.find(key);
        if (iter == keymap.end()) {
            DEBUG("GET", key, "Not found");
            return -1;
        } else {
            datalist.splice(datalist.begin(), datalist, iter->second);
            iter->second = datalist.begin();
            DEBUG("GET", key, datalist);
            return datalist.begin()->second;
        }
    }

    void put(key_t key, val_t value) {
        auto [iter, inserted] = keymap.emplace(key, datalist.end());
        if (inserted) {
            if (datalist.size() >= capacity) {
                keymap.erase(datalist.back().first);
                datalist.pop_back();
            }
            datalist.emplace_front(key, value);
        } else {
            datalist.splice(datalist.begin(), datalist, iter->second);
            datalist.begin()->second = value;
        }
        iter->second = datalist.begin();
        DEBUG("PUT", key, value, datalist);
    }
};

int main(int argc, char *argv[]) {
    LRUCache s(2);
    s.put(1, 1);     // cache is {1=1}
    s.put(2, 2);     // cache is {1=1, 2=2}
    DEBUG(s.get(1)); // return 1
    s.put(3, 3);     // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    DEBUG(s.get(2)); // returns -1 (not found)
    s.put(4, 4);     // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    DEBUG(s.get(1)); // return -1 (not found)
    DEBUG(s.get(3)); // return 3
    DEBUG(s.get(4)); // return 4
    return 0;
}
