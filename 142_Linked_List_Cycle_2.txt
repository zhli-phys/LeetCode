class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        while(temp)
        {
            visited.insert(temp);
            temp = temp->next;
            if (visited.find(temp) != visited.end())
                return temp;
        }
        return NULL;
    }

private:
    unordered_set<ListNode*> visited;
};



class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                ListNode* temp = head;
                while(true)
                {
                    if (temp == slow)
                        return temp;
                    temp = temp->next;
                    slow = slow->next;
                }
            }
        }
        return NULL;
    }
};