class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        auto curr = head;
        while (curr) {
            ++n;
            curr = curr->next;
        }
        for (int i = 0; i < n / 2; ++i)
            head = head->next;
        return head;
    }
};