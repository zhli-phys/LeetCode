class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        encode(root, data);
        if (!data.empty())
            data.pop_back();
        return data;
    }
    
    void encode(TreeNode* root, string& data) {
        if (!root)
            return;
        data += to_string(root->val) + ',';  
        encode(root->left, data);
        encode(root->right, data);              
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        vector<int> nums;
        string curr;
        while (getline(ss, curr, ','))
            nums.push_back(stoi(curr));
        int i = 0;
        return decode(i, nums, INT_MIN, INT_MAX);
    }
    
    TreeNode* decode(int& i, vector<int>& nums, int lowerLimit, int upLimit) {
        if (i >= nums.size() || nums[i] < lowerLimit || nums[i] > upLimit)
            return NULL;
        TreeNode* root = new TreeNode(nums[i]);
        ++i;
        root->left = decode(i, nums, lowerLimit, root->val);
        root->right = decode(i, nums, root->val, upLimit);        
        return root;
    }
};











class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        encode(root, data);
        if (!data.empty())
            data.pop_back();
        return data;
    }
    
    void encode(TreeNode* root, string& data) {
        if (!root)
            return;
        encode(root->left, data);
        encode(root->right, data);
        data += to_string(root->val) + ',';        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        stack<int> nums;
        string curr;
        while (getline(ss, curr, ','))
            nums.push(stoi(curr));
        return decode(nums, INT_MIN, INT_MAX);
    }
    
    TreeNode* decode(stack<int>& nums, int lowerLimit, int upLimit) {
        if (nums.empty() || nums.top() < lowerLimit || nums.top() > upLimit)
            return NULL;
        TreeNode* root = new TreeNode(nums.top());
        nums.pop();
        root->right = decode(nums, root->val, upLimit);
        root->left = decode(nums, lowerLimit, root->val);
        return root;
    }
};











class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        encode(root, data);
        if (!data.empty())
            data.pop_back();
        return data;
    }
    
    void encode(TreeNode* root, string& data) {
        if (!root)
            return;
        data += to_string(root->val) + ',';
        encode(root->left, data);
        encode(root->right, data);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        vector<int> nums;
        string curr;
        while (getline(ss, curr, ','))
            nums.push_back(stoi(curr));
        int n = nums.size();
        return buildTree(0, n, nums);
    }
    
    TreeNode* buildTree(int left, int right, vector<int>& nums) {
        if (left == right)
            return NULL;
        TreeNode* root = new TreeNode(nums[left]);
        int l = left + 1;
        int r = right;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[left])
                r = mid;
            else
                l = mid + 1;
        }
        root->left = buildTree(left + 1, r, nums);
        root->right = buildTree(r, right, nums);
        return root;
    }
};