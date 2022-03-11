class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
        int n = 1;
        auto curr = head;
        while (curr->next) {
            ++n;
            curr = curr->next;
        }
        auto end = curr;
        k %= n;
        if (k == 0)
            return head;
        curr = head;
        for (int i = 0; i < n - k - 1; ++i)
            curr = curr->next;
        auto newHead = curr->next;
        curr->next = nullptr;
        end->next = head;
        return newHead;
    }
};