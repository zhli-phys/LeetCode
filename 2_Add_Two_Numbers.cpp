class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode((l1->val + l2->val) % 10);
        int carry = (l1->val + l2->val) / 10;
        auto curr = head;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 || l2) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }                
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }                
            carry = sum / 10;
            sum %= 10;
            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        if (carry > 0)
            curr->next = new ListNode(carry);
        return head;
    }
};












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