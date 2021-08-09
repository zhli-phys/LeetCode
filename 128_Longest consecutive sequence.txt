class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        unordered_set<int> numbers;
        for (int i = 0; i < len; i++) 
            numbers.insert(nums[i]);
        int sol = 0;
        while(!numbers.empty()) {
            int current = 1;
            unordered_set<int>::iterator it = numbers.begin();
            int left_number = *it - 1;
            int right_number = *it + 1;
            numbers.erase(it);
            unordered_set<int>::iterator left = numbers.find(left_number);
            unordered_set<int>::iterator right = numbers.find(right_number);
            while(left != numbers.end()) {
                current++;
                left_number--;
                numbers.erase(left);
                left = numbers.find(left_number);
            }
            while(right != numbers.end()) {
                current++;
                right_number++;
                numbers.erase(right);
                right = numbers.find(right_number);
            }
            if (current > sol)
                sol = current;
        }
        return sol;
    }
};







class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        unordered_set<int> numbers;
        for (int i = 0; i < len; i++) 
            numbers.insert(nums[i]);
        int sol = 0;
        for(unordered_set<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
            unordered_set<int>::iterator temp = numbers.find(*it - 1);
            if (temp != numbers.end())
                continue;
            int current = 1;
            int right = *it + 1;
            temp = numbers.find(right);
            while(temp != numbers.end()) {
                current++;
                right++;
                temp = numbers.find(right);
            }
            if (current > sol)
                sol = current;
        }
        return sol;
    }
};



















//hash table;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums)
            mp[num] = 1;
        int longest = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            int curr = it->first;
            while (mp.find(++curr) != mp.end()) {
                it->second += mp[curr];
                mp.erase(curr);
            }
            longest = max(longest, it->second);
        }
        return longest;
    }
};

















class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int num : nums)
            st.insert(num);
        int longest = 0;
        for (auto it = st.begin(); it != st.end(); ++it) {
            int curr = *it;
            if (st.find(curr -1) == st.end()) {
                int curr_length = 1;
                while (st.find(++curr) != st.end())
                    ++curr_length;
                longest = max(longest, curr_length);
            } 
        }
        return longest;
    }
};