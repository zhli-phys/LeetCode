class Solution {
public:
    Node* connect(Node* root) {
        Node* prevHead = root;
        while (prevHead) {
            Node* prevCurr = prevHead;
            Node* head = nullptr;
            Node* curr = nullptr;
            while (prevCurr) {
                if (prevCurr->left) {
                    if (!head) {
                        head = prevCurr->left;
                        curr = head;
                    }                    
                    else {
                        curr->next = prevCurr->left;
                        curr = curr->next;
                    }
                }
                if (prevCurr->right) {
                    if (!head) {
                        head = prevCurr->right;
                        curr = head;
                    }
                    else {
                        curr->next = prevCurr->right;
                        curr = curr->next;
                    }
                }
                prevCurr = prevCurr->next;
            }    
            prevHead = head;
        }
        return root;
    }
};













class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return NULL;
        root->left = connect(root->left);
        root->right = connect(root->right);
        Node* curr_left = root->left;
        Node* curr_right = root->right;
        while(curr_left) {
            curr_left->next = curr_right;
            curr_left = curr_left->right;
            curr_right = curr_right->left;
        }
        return root;
    }
};