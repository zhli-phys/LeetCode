/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        bool allEqual = false;
        Node* curr = head;
        while (curr->next->val == curr->val) {
            curr = curr->next;
            if (curr == head) {
                allEqual = true;
                break;
            }
        }
        if (allEqual) {
            head->next = new Node(insertVal, head->next);
            return head;
        }
        curr = head;
        if (curr->val <= insertVal) {
            while (curr->next->val >= curr->val && curr->next->val < insertVal)
                curr = curr->next;
            curr->next = new Node(insertVal, curr->next);
        }
        else {
            bool inserted = false;
            while (curr->next->val >= curr->val)
                curr = curr->next;
            if (curr->next->val < insertVal)
                curr->next = insert(curr->next, insertVal);
            else
                curr->next = new Node(insertVal, curr->next);
        }
        return head;
    }
};