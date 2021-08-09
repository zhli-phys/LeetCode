//O(n^2 * k) 1068 ms 5%; O(1) 24.1 MB 99.5%
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == i)
                    continue;
                int n1 = words[i].size();
                int n2 = words[j].size();
                int left = 0;
                int right = n2 - 1;
                bool flag = true;
                if (n1 >= n2) {
                    while (right >= 0) {
                        if (words[i][left] != words[j][right]) {
                            flag = false;
                            break;
                        }
                        ++left;
                        --right;
                    }
                    if (flag) {
                        right = n1 - 1;
                        while (left < right) {
                            if (words[i][left] != words[i][right]) {
                                flag = false;
                                break;
                            }
                            ++left;
                            --right;
                        }
                    }
                }
                else {
                    while (left < n1) {
                        if (words[i][left] != words[j][right]) {
                            flag = false;
                            break;
                        }
                        ++left;
                        --right;
                    }
                    if (flag) {
                        left = 0;
                        while (left < right) {
                            if (words[j][left] != words[j][right]) {
                                flag = false;
                                break;
                            }
                            ++left;
                            --right;
                        }
                    }
                }
                if (flag)
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};






















//O(n^2 * k) time limit exceeded 
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == i)
                    continue;
                auto curr = words[i] + words[j];
                int m = curr.size();
                int left = 0;
                int right = m - 1;
                bool flag = true;
                while (left < right) {
                    if (curr[left] != curr[right]) {
                        flag = false;
                        break;
                    }
                    ++left;
                    --right;
                }
                if (flag)
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};





















//hash table; O(n * k^2) 192 ms 79%; 70.5 MB 55%
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> ans;
        unordered_map<string, vector<int>> prefix;
        unordered_map<string, vector<int>> suffix;
        unordered_map<string, vector<int>> rever;
        for (int i = 0; i < n; ++i) {
            int k = words[i].size();
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            rever[rev].push_back(i);
            for (int j = 0; j < k; ++j) {
                bool flag = true;
                int left = j;
                int right = k - 1;
                while (left < right) {
                    if (words[i][left] != words[i][right]) {
                        flag = false;
                        break;
                    }
                    ++left;
                    --right;
                }
                if (flag)
                    prefix[words[i].substr(0, j)].push_back(i);
                
                flag = true;
                left = 0;
                right = k - 1 - j;
                while (left < right) {
                    if (words[i][left] != words[i][right]) {
                        flag = false;
                        break;
                    }
                    ++left;
                    --right;
                }
                if (flag) {
                    rev = words[i].substr(k - j);
                    reverse(rev.begin(), rev.end());
                    suffix[rev].push_back(i);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            auto curr = words[i];
            auto it = rever.find(curr);
            if (it != rever.end()) {
                for (int j : it->second) {
                    if (j != i)
                        ans.push_back({i, j});
                }
            }
            it = suffix.find(curr);
            if (it != suffix.end()) {
                for (int j : it->second) {
                    if (j != i)
                        ans.push_back({i, j});
                }
            }
            reverse(curr.begin(), curr.end());
            it = prefix.find(curr);
            if (it != prefix.end()) {
                for (int j : it->second) {
                    if (j != i)
                        ans.push_back({j, i});
                }
            }
        }
        return ans;
    }
};