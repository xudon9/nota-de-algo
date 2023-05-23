#include "../../common.hpp"
// https://leetcode.com/problems//description/

class KthLargest {
    vector<int> q;
    #define OP q.begin(), q.end(), greater<int>()
public:
    KthLargest(int k, vector<int>& nums) {
        q.reserve(k+1);
        for (int n : nums) {
            q.push_back(n);
            if (q.size() == k)
                make_heap(OP);
            else if (q.size() == k + 1) {
                push_heap(OP);
                pop_heap(OP);
                q.pop_back();
            }
        }

        while (q.size() < k) {
            q.push_back(-10009);
            push_heap(OP);
        }
    }

    int add(int val) {
        q.push_back(val);
        push_heap(OP);
        pop_heap(OP);
        q.pop_back();
        return q.front();
    }

    #undef OP
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
