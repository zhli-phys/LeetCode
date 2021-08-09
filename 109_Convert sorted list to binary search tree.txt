class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vec;
        while(head) {
            vec.push_back(head->val);
            head = head->next;
        }
        int n = vec.size();
        return BST(0, n, vec);
    }
    
    TreeNode* BST(int left, int right, vector<int>& vec) {
        if (left >= right)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = BST(left, mid, vec);
        root->right = BST(mid + 1, right, vec);
        return root;
    }
};









//No extra vector
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* curr = head;
        while (curr) {
            ++n;
            curr = curr->next;
        }
        return helper(0, n, head);
    }
    
    TreeNode* helper(int left, int right, ListNode *&head) {
        if (left >= right)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode* l = helper(left, mid, head);
        TreeNode* root = new TreeNode(head->val);
        root->left = l;
        head = head->next;
        root->right = helper(mid + 1, right, head);
        return root;
    }
};