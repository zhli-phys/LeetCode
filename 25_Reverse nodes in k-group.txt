//recursive; O(n) 16 ms 62%; O(n/k) 11.4 MB 67%
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        for (int i = 0; i < k; ++i) {
            if (!curr)
                return head;
            curr = curr->next;
        }
        ListNode* prev = head;
        curr = prev->next;
        for (int i = 1; i < k; ++i) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};








//iterative; O(n) 4 ms 100%; O(1) 11.4 MB 67%
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        for (int i = 0; i < k; ++i) {
            if (!curr)
                return head;
            curr = curr->next;
        }
        ListNode* prev = head;
        curr = prev->next;
        for (int i = 1; i < k; ++i) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        ListNode* newHead = prev;
        ListNode* preTail = head;
        head = curr;
        while (true) {
            bool flag = true;
            for (int i = 0; i < k; ++i) {
                if (!curr) {
                    preTail->next = head;
                    flag = false;
                    break;
                }
                curr = curr->next;
            }
            if (!flag)
                break;
            prev = head;
            curr = prev->next;
            for (int i = 1; i < k; ++i) {
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            preTail->next = prev;
            preTail = head;
            head = curr;
        }
        return newHead;
    }
};