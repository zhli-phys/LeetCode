\\priority_queue of pair<int, int>; O(n log k) 376 ms 11%; O(n) 90.5 MB 33%
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> prev;
        int curr_score = nums[0];
        prev.push({curr_score, 0});
        for (int i = 1; i < n; ++i) {
            while (i - prev.top().second > k)
                prev.pop();
            curr_score = prev.top().first + nums[i];
            prev.push({curr_score, i});
        }
        return curr_score;
    }
};









\\priority queue of int with hash table; O(n log k) 312 ms 23%; O(n) 119.7 MB 22%
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> pos;
        priority_queue<int> prev;
        int curr_score = nums[0];
        prev.push(curr_score);
        pos[curr_score] = 0;
        for (int i = 1; i < n; ++i) {
            while (i - pos[prev.top()] > k)
                prev.pop();
            curr_score = prev.top() + nums[i];
            prev.push(curr_score);
            pos[curr_score] = i;
        }
        return curr_score;
    }
};










\\decreasing deque; O(n) 244 ms 30%; O(n) 217.7 MB 5%
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> scores(n);
        deque<int> prev;
        prev.push_front(0);
        scores[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (i - prev.back() > k)
                prev.pop_back();
            scores[i] = scores[prev.back()] + nums[i];
            while (!prev.empty() && scores[prev.front()] <= scores[i])
                prev.pop_front();
            prev.push_front(i);
        }
        return scores.back();
    }
};















//decreasing stack using vector<int> with pointer; O(n) 180 ms 50%; O(n) 81.1 MB 56%
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> scores(n);
        vector<int> prev;
        prev.push_back(0);
        scores[0] = nums[0];
        int index = 0;
        for (int i = 1; i < n; ++i) {
            if (i - prev[index] > k)
                ++index;
            scores[i] = scores[prev[index]] + nums[i];
            while (!prev.empty() && i - prev.back() < k && scores[prev.back()] <= scores[i])
                prev.pop_back();
            prev.push_back(i);
        }
        return scores.back();
    }
};


















//(compressed) decreasing stack using vector<int> with pointer; O(n) 188 ms 48%; O(n) 77.7 MB 84%
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> scores(n);
        vector<int> prev;
        prev.push_back(0);
        scores[0] = nums[0];
        int index = 0;
        for (int i = 1; i < n; ++i) {
            if (i - prev[index] > k)
                ++index;
            scores[i] = scores[prev[index]] + nums[i];
            while (!prev.empty() && i - prev.back() < k && scores[prev.back()] <= scores[i])
                prev.pop_back();
            prev.push_back(i);
        }
        return scores.back();
    }
};