class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map.count(val))
            return false;
        else {
            int n = nums.size();
            map[val] = n;
            nums.push_back(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (map.count(val)) {
            int n = nums.size();
            int pos = map[val];
            map.erase(val);
            if (pos < n-1) {
                nums[pos] = nums[n-1];
                map[nums[n-1]] = pos;
            }
            nums.pop_back();
            return true;
        }
        else
            return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int n = nums.size();
        int i = rand() % n;
        return nums[i];
    }
    
private:
    unordered_map<int, int> map;
    vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */