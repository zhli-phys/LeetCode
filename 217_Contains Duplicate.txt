class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (auto num : nums) {
            if (st.count(num))
                return true;
            else
                st.insert(num);
        }
        return false;
    }
};