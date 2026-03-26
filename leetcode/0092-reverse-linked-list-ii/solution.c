/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;

    struct ListNode* prev = &dummy;
    int pos = 1;

    while (pos < left) {
        prev = prev->next;
        pos = pos + 1;
    }

    struct ListNode* cur = prev->next;

    int moves = right - left;
    while (moves > 0) {
        struct ListNode* move = cur->next;

        cur->next = move->next;
        move->next = prev->next;
        prev->next = move;
        moves = moves - 1;
    }

    return dummy.next;
}
