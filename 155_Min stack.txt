class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        nums.push_back(x);
        if (nums.size() == 1)
            min = x;
        else if (x < min)
            min = x;
    }
    
    void pop() {
        int last = nums.back();
        nums.pop_back();
        if (min == last)
            min = *min_element(nums.begin(), nums.end());
    }
    
    int top() {
        return nums.back();
    }
    
    int getMin() {
        return min;
    }
    
private:
    vector<int> nums;
    int min;
};








class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (nums.empty()) {
            nums.push_back(pair<int, int>(x, x));
        }
        else {
            int min = nums.back().second;
            if (x < min)
                min = x;
            nums.push_back(pair<int, int>(x, min));
        }
    }
    
    void pop() {
        nums.pop_back();
    }
    
    int top() {
        return nums.back().first;
    }
    
    int getMin() {
        return nums.back().second;
    }
    
private:
    vector<pair<int, int>> nums;
};
