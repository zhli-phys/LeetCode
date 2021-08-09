class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return NULL;
        if (!head->next)
            return head;
        ListNode* newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
};





class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return NULL;
        stack<ListNode*> nodes;
        while (head) {
            nodes.push(head);
            head = head->next;
        }
        head = nodes.top();
        nodes.pop();
        ListNode* current = head;
        while (!nodes.empty()) {
            current->next = nodes.top();
            nodes.pop();
            current = current->next;
        }
        current->next = NULL;
        return head;
    }
};






class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return NULL;
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* nextnode = current->next;
        while (nextnode) {
            current->next = prev;
            prev = current;
            current = nextnode;
            nextnode = nextnode->next;
        }
        current->next = prev;
        return current;
    }
};