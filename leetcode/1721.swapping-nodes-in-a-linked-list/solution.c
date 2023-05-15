/**
 * URL: https://leetcode.com/problems/swapping-nodes-in-a-linked-list
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapNodes(struct ListNode* head, int k){
  int len = 0, i = 0;
  int *ptr = 0;
  struct ListNode* iter = head;
  for (iter = head; iter; iter = iter->next, ++len)
    ;
  for (iter = head; iter; iter = iter->next, ++i) {
    if (i + 1 == k || i == len - k) {
      if (ptr) {
        int tmp = iter->val;
        iter->val = *ptr;
        *ptr = tmp;
        break;
      } else {
        ptr = &(iter->val);
      }
    }
  }
  return head;
}
