class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> nums;
        ListNode* current = head;
        while (current) {
            nums.push(current->val);
            current = current->next;
        }
        current = head;
        while (current) {
            if (current->val != nums.top())
                return false;
            current = current->next;
            nums.pop();
        }
        return true;
    }
};