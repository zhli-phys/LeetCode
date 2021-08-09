class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;
        visited.insert(head);
        if (visited.find(head->next) != visited.end())
            return true;
        if (hasCycle(head->next))
            return true;
        return false;
    }

private:
    unordered_set<ListNode*> visited;
};



class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};