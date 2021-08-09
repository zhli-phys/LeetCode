/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

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