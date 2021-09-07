class Solution {
public:
    Solution(int n, vector<int>& blacklist) : count(blacklist.size()) {
        int m = blacklist.size();
        valid_n = n - m;
        sort(blacklist.begin(), blacklist.end());
        for (int i = 0; i < m; ++i) 
            count[i] = blacklist[i] - i;
    }
    
    int pick() {
        int choice = rand() % valid_n;
        auto it = upper_bound(count.begin(), count.end(), choice);
        return it - count.begin() + choice;
    }
    
private:
    int valid_n;
    vector<int> count;
};








class Solution {
public:
    Solution(int n, vector<int>& blacklist) {
        int m = blacklist.size();
        valid_n = n - m;
        sort(blacklist.begin(), blacklist.end());
        auto it = lower_bound(blacklist.begin(), blacklist.end(), valid_n);
        int target = valid_n;
        for (int num : blacklist) {
            if (num >= valid_n)
                break;
            while (it != blacklist.end() && target == *it) {
                ++target;
                ++it;
            }
            mp[num] = target;
            ++target;
        }
    }
    
    int pick() {
        int choice = rand() % valid_n;
        if (mp.find(choice) != mp.end())
            return mp[choice];
        else
            return choice;
    }
    
private:
    int valid_n;
    unordered_map<int, int> mp;
};