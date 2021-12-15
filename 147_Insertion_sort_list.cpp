class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head)
            return head;
        ListNode* curr = head;
        while (curr->next) {
            if (head->val > curr->next->val) {
                auto temp = curr->next;
                curr->next = curr->next->next;
                temp->next = head;
                head = temp;
            }
            else {
                ListNode* idx = head;
                while (idx != curr && idx->next->val < curr->next->val)
                    idx = idx->next;
                if (idx == curr) {
                    curr = curr->next;
                }
                else {
                    auto currNext = curr->next;
                    curr->next = curr->next->next;
                    currNext->next = idx->next;
                    idx->next = currNext;
                }
            }
        }
        return head;
    }
};