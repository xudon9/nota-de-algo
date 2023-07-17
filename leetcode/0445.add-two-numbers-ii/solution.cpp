#include "../../common.hpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
//  https://leetcode.com/problems/add-two-numbers-ii

struct Solution {
    static ListNode *reverse(ListNode *head) {
        ListNode *prev{};
        while (head) {
            ListNode *tail = head->next;
            head->next = prev;
            prev = head;
            head = tail;
        }
        return prev;
    }

    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1->val == 0)
            return l2;
        if (l2->val == 0)
            return l1;
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode *ret{};
        bool carry{};
        while (l1 && l2) {
            int n = carry + l1->val + l2->val;
            carry = n >= 10;
            ret = new ListNode(n % 10, ret);
            l1 = l1->next;
            l2 = l2->next;
        }
        if (!l1) {
            l1 = l2;
        }
        while (l1) {
            int n = carry + l1->val;
            carry = n >= 10;
            ret = new ListNode(n % 10, ret);
            l1 = l1->next;
        }
        if (carry)
            ret = new ListNode(1, ret);
        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution s;
    return 0;
}
