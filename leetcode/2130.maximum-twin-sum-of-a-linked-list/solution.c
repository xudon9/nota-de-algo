/* https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* Link;

Link reverse(Link head) {
    Link tail = NULL;
    while (head) {
        Link todo = head->next;
        head->next = tail;
        tail = head;
        head = todo;
    }
    return tail;
}

int length(Link head) {
    int n;
    for (n = 0; head; head = head->next)
        ++n;
    return n;
}

Link nth(Link head, int n) {
    int i;
    for (i = 0; i < n; ++i) {
        head = head->next;
    }
    return head;
}

int pairSum(Link head){
    int len = length(head), res = 0;
    Link half = reverse(nth(head, len / 2));
    // head[len/2-1]->next is not set to null, so iterattion should not
    // be based on "head"
    while (half) {
        int s = head->val + half->val;
        res = s > res ? s : res;
        head = head->next;
        half = half->next;
    }
    return res;
}

