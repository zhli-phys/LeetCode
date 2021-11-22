class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (int num : nums) {
            if (used.find(num) == used.end()) {
                uniqueVal.push(num);
                used.insert(num);
            }                
            else
                repeated.insert(num);
        }
    }
    
    int showFirstUnique() {
        while (!uniqueVal.empty() && repeated.find(uniqueVal.front()) != repeated.end())
            uniqueVal.pop();
        if (uniqueVal.empty())
            return -1;
        else
            return uniqueVal.front();
    }
    
    void add(int value) {
        if (used.find(value) == used.end()) {
            uniqueVal.push(value);
            used.insert(value);
        }
        else
            repeated.insert(value);
    }
    
private:
    queue<int> uniqueVal;
    unordered_set<int> used;
    unordered_set<int> repeated;
};