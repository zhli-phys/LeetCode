//recursive; O(n) 100 ms; O(n) 7.6 MB 50%
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* second = head->next;
        ListNode* third = second->next;
        second->next = head;
        head->next = swapPairs(third);
        return second;
    }
};










//iterative; O(n) 4 ms 62%; O(1) 7.6 MB 50%
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* newhead = head->next;
        ListNode* prev = NULL;
        while (head && head->next) {
            ListNode* second = head->next;
            ListNode* third = second->next;
            second->next = head;
            head->next = third;
            if (prev)
                prev->next = second;
            prev = head;
            head = third;
        }
        return newhead;
    }
};