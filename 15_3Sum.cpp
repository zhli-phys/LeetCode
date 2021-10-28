class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, unordered_map<int, unordered_set<int>>> tri;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i == 0 || nums[i] != nums[i-1]) {
                int j = i + 1;
                int k = n - 1;
                while (j < k) {
                    int curr = nums[i] + nums[j] + nums[k];
                    if (curr > 0) 
                        --k;
                    else if (curr < 0)
                        ++j;
                    else {
                        tri[nums[i]][nums[j]].insert(nums[k]);
                        ++j;
                        --k;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for (auto it = tri.begin(); it != tri.end(); ++it) 
            for (auto it1 = it->second.begin(); it1 != it->second.end(); ++it1) 
                for (auto it2 = it1->second.begin(); it2 != it1->second.end(); ++it2)
                    ans.push_back({it->first, it1->first, *it2});
        return ans;
    }
};










class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        unordered_set<int> distinct_nums;
        unordered_set<int> double_nums;
        int zero_counts = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                zero_counts++;
            unordered_set<int>::iterator it = distinct_nums.find(nums[i]);
            if (it == distinct_nums.end())
                distinct_nums.insert(nums[i]);
            else {
                if (nums[i])
                    double_nums.insert(nums[i]);
            }
        }
        if (zero_counts >= 3) 
            results.push_back(vector<int>(3, 0));
        for (unordered_set<int>::iterator it = double_nums.begin(); it != double_nums.end(); it++) {
            unordered_set<int>::iterator it2 = distinct_nums.find(-2 * (*it));
            if (it2 != distinct_nums.end()) {
                int a[] = { *it, *it, *it2 };
                vector<int> num(a, a + 3);
                results.push_back(num);
            }
        }
        unordered_map<int, vector<int>> two_sums;
        for (unordered_set<int>::iterator it = distinct_nums.begin(); it != distinct_nums.end(); it++) {
            unordered_map<int, vector<int>>::iterator it_sum = two_sums.find(-(*it));
            if (it_sum != two_sums.end()) {
                for (int i = 0; i < it_sum->second.size(); i++) {
                    int a[] = { *it, it_sum->second[i], -(*it) - it_sum->second[i] };
                    vector<int> num(a, a + 3);
                    results.push_back(num);
                }
            }
            for (unordered_set<int>::iterator it2 = distinct_nums.begin(); it2 != it; it2++) {
                two_sums[(*it) + (*it2)].push_back(*it);
            }
        }
        return results;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1, k = len - 1; j < k; ) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    j++;
                    continue;
                }
                if (k < len - 1 && nums[k] == nums[k + 1]) {
                    k--;
                    continue;
                }
                if (nums[i] + nums[j] + nums[k] == 0) {
                    int a[] = { nums[i], nums[j], nums[k] };
                    results.push_back(vector<int>(a, a + 3));
                    j++;
                    k--;
                }
                else {
                    if (nums[i] + nums[j] + nums[k] > 0)
                        k--;
                    else
                        j++;
                }
            }
        }
        return results;
    }
};