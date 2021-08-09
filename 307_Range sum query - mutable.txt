class NumArray {
public:
    NumArray(vector<int>& nums) : n(nums.size()), nums(nums), sums(4 * n + 1) {
        build(0, 0, n);
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        inner_update(0, 0, n, index, diff);
    }
    
    int sumRange(int left, int right) {
        return inner_sum(0, 0, n, left, right + 1);
    }
    
private:
    int build(int i, int l, int r) {
        if (r == l + 1) 
            sums[i] = nums[l];
        else {
            int mid = (l + r) / 2;
            sums[i] = build(2 * i + 1, l, mid) + build(2 * i + 2, mid, r);
        }        
        return sums[i];
    }
    
    void inner_update(int i, int l, int r, int index, int diff) {
        if (index >= l && index < r) {
            sums[i] += diff;
            if (r == l + 1) 
                return;
            int mid = (l + r) / 2;
            inner_update(2 * i + 1, l, mid, index, diff);
            inner_update(2 * i + 2, mid, r, index, diff);
        }
    }
    
    int inner_sum(int i, int l, int r, int left, int right) {
        if (right <= l || left >= r)
            return 0;
        if (l >= left && r <= right)
            return sums[i];
        int mid = (l + r) / 2;
        return inner_sum(2 * i + 1, l, mid, left, right) + inner_sum(2 * i + 2, mid, r, left, right);
    }
    
    int n;
    vector<int> nums;
    vector<int> sums;
};















class NumArray {
public:
    NumArray(vector<int>& nums) : n(nums.size()), vec(4*nums.size()+1) {
        build(0, 0, n, nums);
    }
    
    void update(int index, int val) {
        insert(index, 0, 0, n, val);
    }
    
    int sumRange(int left, int right) {
        return sums(left, ++right, 0, 0, n);
    }
    
private:
    int build(int node, int i, int j, vector<int>& nums) {
        if (j == i + 1) 
            vec[node] = nums[i];
        else {
            int mid = (i + j) / 2;
            vec[node] = build(2 * node + 1, i, mid, nums) + build(2 * node + 2, mid, j, nums);
        }
        return vec[node];
    }
    
    int insert(int index, int node, int i, int j, int val) {
        if (index >= i && index < j) {
            if (j == i + 1) {
                int diff = val - vec[node];
                vec[node] = val;
                return diff;
            }
            int mid = (i + j) / 2;
            int diff = insert(index, 2 * node + 1, i, mid, val) + insert(index, 2 * node + 2, mid, j, val);
            vec[node] += diff;
            return diff;
        }
        else
            return 0;
    }
    
    int sums(int left, int right, int node, int i, int j) {
        if (left >= j || right <= i)
            return 0;
        else if (left <= i && right >= j) 
            return vec[node];
        else {
            int mid = (i + j) / 2;
            return sums(left, right, 2 * node + 1, i, mid) + sums(left, right, 2 * node + 2, mid, j);
        }
    }
    
    vector<int> vec;
    int n;
};