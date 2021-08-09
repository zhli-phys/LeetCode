//Time limit exceeded
class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums(nums2) {
        for (int num : nums1)
            ++mp[num];
    }
    
    void add(int index, int val) {
        nums[index] += val;
    }
    
    int count(int tot) {
        int ans = 0;
        for (int num : nums) {
            auto it = mp.find(tot - num);
            if (it != mp.end())
                ans += it->second;
        }
        return ans;
    }
    
private:
    unordered_map<int, int> mp;
    vector<int> nums;
};









//save nums2 in an unordered map
//256 ms, fater than 93.33%; 73.8 MB, less than 83.53%
class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums1(nums1), nums2(nums2) {
        for (int num : nums2)
            ++mp[num];
    }
    
    void add(int index, int val) {
        auto it = mp.find(nums2[index]);
        --(it->second);
        if (it->second == 0)
            mp.erase(it);
        nums2[index] += val;
        ++mp[nums2[index]];
    }
    
    int count(int tot) {
        int ans = 0;
        for (int num : nums1) {
            auto it = mp.find(tot - num);
            if (it != mp.end())
                ans += it->second;
        }
        return ans;
    }
    
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> mp;
};