/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = 0;
    struct ListNode* cur = head;

    while (cur != 0) {
        struct ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}
