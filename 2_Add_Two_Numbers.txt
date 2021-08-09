class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* result = new ListNode();
        int temp = l1->val + l2->val;
        result->val = temp % 10;
        carry = temp / 10;
        l1 = l1->next;
        l2 = l2->next;
        ListNode* end = result;
        while (l1 || l2) {
            end->next = new ListNode();
            end = end->next;
            if (l1 && l2) {
                temp = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
                end->val = temp % 10;
                carry = temp / 10;
            }
            else {
                if (l1) {
                    temp = l1->val + carry;
                    l1 = l1->next;
                    end->val = temp % 10;
                    carry = temp / 10;
                }
                else {
                    temp = l2->val + carry;
                    l2 = l2->next;
                    end->val = temp % 10;
                    carry = temp / 10;
                }
            }
        }
        if (carry == 1) {
            end->next = new ListNode();
            end = end->next;
            end->val = 1;
        }
        return result;
    }
};