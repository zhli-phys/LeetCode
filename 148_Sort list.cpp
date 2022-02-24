class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int n = 0;
        auto curr = head;
        while (curr) {
            ++n;
            curr = curr->next;
        }
        if (n <= 1)
            return head;
        return sortList(head, n);
    }
    
    ListNode* sortList(ListNode*& head, int len) {
        if (len == 1) {
            auto curr = head;
            head = head->next;
            curr->next = nullptr;
            return curr;
        }
        auto left = sortList(head, len / 2);
        auto right = sortList(head, len - len / 2);
        return merge(left, right);
    }
    
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* head = nullptr;
        if (left->val <= right->val) {
            head = left;
            left = left->next;
        }
        else {
            head = right;
            right = right->next;
        }
        auto prev = head;
        prev->next = nullptr;
        while (left && right) {
            if (left->val <= right->val) {
                prev->next = left;
                left = left->next;
            }
            else {
                prev->next = right;
                right = right->next;
            }
            prev = prev->next;
        }
        if (left)
            prev->next = left;
        else
            prev->next = right;
        return head;
    }
};

















class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head)
            return NULL;
        ListNode* current = head;
        int len = 0;
        while(current) {
            len++;
            current = current->next;
        }
        return sortList(head, len);
    }
    
    ListNode* sortList(ListNode* head, int len) {
        if (len == 1) {
            head->next = NULL;
            return head;
        }
        ListNode* middle = head;
        int half_len = len / 2;
        for (int i = 0; i < half_len; i++)
            middle = middle->next;
        ListNode* left = sortList(head, half_len);
        ListNode* right = sortList(middle, len - half_len);
        if (left->val > right->val) {
            head = right;
            right = right->next;
        }
        else {
            head = left;
            left = left->next;
        }
        ListNode* current = head;
        while (left && right) {
            if (left->val > right->val) {
                current->next = right;
                right = right->next;
                current = current->next;
            }
            else {
                current->next = left;
                left = left->next;
                current = current->next;
            }
        }
        if (left)
            current->next = left;
        else
            current->next = right;
        return head;
    }
};