class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> num1;
        inOrder(root1, num1);
        vector<int> num2;
        inOrder(root2, num2);
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> ans;
        int i = 0;
        int j = 0;
        while (i < n1 || j < n2) {
            if (i == n1) {
                ans.push_back(num2[j]);
                ++j;
            }
            else if (j == n2) {
                ans.push_back(num1[i]);
                ++i;
            }
            else {
                if (num1[i] <= num2[j]) {
                    ans.push_back(num1[i]);
                    ++i;
                }
                else {
                    ans.push_back(num2[j]);
                    ++j;
                }
            }
        }
        return ans;
    }
    
    void inOrder(TreeNode* root, vector<int>& num) {
        if (!root)
            return;
        inOrder(root->left, num);
        num.push_back(root->val);
        inOrder(root->right, num);
    }
};