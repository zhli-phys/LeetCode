class Solution {
public:
    int diameter(Node* root) {
        unordered_map<Node*, int> height;
        int ans = 0;
        explore(root, height, ans);
        return ans;
    }
    
    void explore(Node* root, unordered_map<Node*, int>& height, int& ans) {
        if (!root)
            return;
        int first = 0;
        int second = 0;
        for (auto child : root->children) {
            explore(child, height, ans);
            int h = high(child, height);
            if (h > first) {
                second = first;
                first = h;
            }
            else if (h > second) {
                second = h;
            }
        }
        ans = max(ans, first + second);
    }
    
    int high(Node* root, unordered_map<Node*, int>& height) {
        if (!root)
            return 0;
        if (height.find(root) != height.end())
            return height[root];
        int curr = 0;
        for (auto child : root->children) {
            int h = high(child, height);
            curr = max(h, curr);
        }
        ++curr;
        height[root] = curr;
        return curr;
    }
};