class Solution {
public:
    Node* flatten(Node* head) {
        if (!head)
            return head;
        auto p = helper(head);
        return p.first;
    }
    
    pair<Node*, Node*> helper(Node* head) {
        if (head->child && head->next) {
            auto p = helper(head->child);
            auto q = helper(head->next);
            head->child = nullptr;
            head->next = p.first;
            p.first->prev = head;
            p.second->next = q.first;
            q.first->prev = p.second;
            return {head, q.second};
        }
        else if (head->child) {
            auto p = helper(head->child);
            head->child = nullptr;
            head->next = p.first;
            p.first->prev = head;
            return {head, p.second};
        }
        else if (head->next) {
            auto q = helper(head->next);
            return {head, q.second};
        }
        else 
            return {head, head};
    }
};