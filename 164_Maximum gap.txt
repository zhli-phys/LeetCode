//sort, O(n log n), 4 ms, 8.6 MB
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_gap = 0;
        size_t n = nums.size();
        for (size_t i = 1; i < n; ++i) 
            max_gap = max(max_gap, nums[i] - nums[i-1]);
        return max_gap;
    }
};







//Radix sort with dynamically allocated memory, O(n), 8 ms, 10.1 MB
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int dig = 1;
        int max_num = *max_element(nums.begin(), nums.end());
        while (max_num / dig > 0) {
            vector<queue<int>> vec(10);
            for (int num : nums) 
                vec[(num / dig) % 10].push(num);
            size_t index = 0;
            for (int i = 0; i < 10; ++i) {
                while(!vec[i].empty()) {
                    nums[index++] = vec[i].front();
                    vec[i].pop();
                }
            }
            dig *= 10;
        }
        
        int max_gap = 0;
        size_t n = nums.size();
        for (size_t i = 1; i < n; ++i) 
            max_gap = max(max_gap, nums[i] - nums[i-1]);
        return max_gap;
    }
};









//Radix sort without dynamical allocated memory, O(n), 8 ms, 9 MB
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> aux(n);
        int dig = 1;
        int max_num = *max_element(nums.begin(), nums.end());
        while (max_num / dig > 0) {
            vector<int> count(10);
            vector<int> pos(10);
            for (int num : nums)
                ++count[(num / dig) % 10];
            for (int i = 1; i < 10; ++i) 
                pos[i] = pos[i-1] + count[i-1];
            for (int num : nums) 
                aux[pos[(num / dig) % 10]++] = num;
            for (size_t i = 0; i < n; ++i)
                nums[i] = aux[i];
            dig *= 10;
        }
        
        int max_gap = 0;
        for (size_t i = 1; i < n; ++i) 
            max_gap = max(max_gap, nums[i] - nums[i-1]);
        return max_gap;
    }
};

















//Buckets and the Pigeonhole principle, O(n), 4 ms, 9 MB
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int num : nums) {
            maxi = max(maxi, num);
            mini = min(mini, num);
        }
        int dist = max((maxi - mini) / (n - 1), 1);
        int num_bucket = (maxi - mini) / dist + 1;
        vector<int> bucket_max(num_bucket, -1);
        vector<int> bucket_min(num_bucket, INT_MAX);
        for (int num : nums) {
            int index = (num - mini) / dist;
            bucket_max[index] = max(bucket_max[index], num);
            bucket_min[index] = min(bucket_min[index], num);
        }
        int max_gap = 0;
        int prev_max = bucket_max[0];
        for (int i = 1; i < num_bucket; ++i) {
            if(bucket_max[i] >= 0) {
                max_gap = max(max_gap, bucket_min[i] - prev_max);
                prev_max = bucket_max[i];
            }
        }
        return max_gap;
    }
};