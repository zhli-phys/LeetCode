//O(n) 0 ms 100%; O(1) 7.4 ms 57%
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (right - left < 1)
            return head;
        ListNode* prev_left = (left == 1 ? nullptr : head);
        for (int i = 2; i < left; ++i)
            prev_left = prev_left->next;
        ListNode* curr_left = prev_left? prev_left->next : head;
        ListNode* curr_right = curr_left->next;
        ListNode* next_right = curr_right->next;
        ListNode* prev = curr_left;
        for (int i = 1; i < right - left; ++i) {
            curr_right->next = prev;
            prev = curr_right;
            curr_right = next_right;
            next_right = next_right->next;
        }
        curr_right->next = prev;
        if (prev_left)
            prev_left->next = curr_right;
        curr_left->next = next_right;
        return prev_left ? head : curr_right;
    }
};