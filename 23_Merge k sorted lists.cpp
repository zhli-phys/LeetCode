class Solution {
public:     
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, larger> pq;
        for (int i = 0; i < k; i++) {
            if (lists[i])
                pq.push(lists[i]);
        }
        if (pq.empty()) 
            return NULL;
        ListNode* head = pq.top();
        pq.pop();
        if (head->next) 
            pq.push(head->next);
        ListNode* current = head;
        while(!pq.empty()) {
            current->next = pq.top();
            current = current->next;
            pq.pop();
            if (current->next)
                pq.push(current->next);
        }
        return head;
    }

private:
    struct larger {
        bool operator() (ListNode* a, ListNode* b) { 
            return a->val > b->val; 
        }
    };
};