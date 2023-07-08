#include "../../common.hpp"
#include <algorithm>
#include <numeric>
// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
//  https://leetcode.com/problems/put-marbles-in-bags/

// template <class T, class Comp> struct Heap {
//     T *buf;
//     int size;
//     int cap;
//
//     Heap(T *buf, int cap) : buf{buf}, size(),cap{cap} {}
//
//     void push(T v) {
//         buf[size++]=v;
//         std::push_heap(buf, buf+size, Comp());
//     }
//
//
//     T pop(){
//         std::pop_heap( buf,buf+size,Comp());
//         return buf[--size];
//     }
// };

class Solution {
  public:
    static long long putMarbles(const vector<int> &weights, int k) {
        int n = weights.size() - 1;
        int sums[10005]; // why n not ok????
        for (int i = 0; i < n; ++i) {
            sums[i] = weights[i] + weights[i + 1];
        }
        std::sort(sums, sums + n);
        auto min = std::accumulate(sums, sums + k - 1, 0ll);
        // DEBUG(n - k, sizeof min);
        auto max = std::accumulate(sums + n - k + 1, sums + n, 0ll);
        return max - min;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    TEST(4, s.putMarbles({1, 3, 5, 1}, 2));
    TEST(0, s.putMarbles({1, 3}, 2));
    return 0;
}
