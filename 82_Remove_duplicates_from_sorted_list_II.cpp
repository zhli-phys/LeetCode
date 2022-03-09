class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            bool duplicate = false;
            while (curr->next && curr->val == curr->next->val) {
                duplicate = true;
                curr->next = curr->next->next;
            }
            if (duplicate) {
                if (prev) {
                    prev->next = curr->next;
                }
                else {
                    head = curr->next;
                }
            }
            else 
                prev = curr;
            curr = curr->next;
        }
        return head;
    }
};