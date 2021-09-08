class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums1_st;
        for (int num : nums1)
            nums1_st.insert(num);
        unordered_set<int> intersection;
        for (int num : nums2)
            if (nums1_st.find(num) != nums1_st.end())
                intersection.insert(num);
        vector<int> ans;
        for (int num : intersection)
            ans.push_back(num);
        return ans;
    }
};