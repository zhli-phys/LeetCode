//hard coded, bfs; 52 ms 94%; 12.8 MB 97%
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<bool> dp(10000, false);
        for (auto&& deadend : deadends)
            dp[stoi(deadend)] = true;
        if (dp[0])
            return -1;
        queue<int> q;
        q.push(stoi(target));
        int step = 0;
        while (!q.empty()) {
            int m = q.size();
            for (int i = 0; i < m; ++i) {
                int curr = q.front();
                q.pop();
                if (curr == 0) 
                    return step;
                if (dp[curr])
                    continue;
                dp[curr] = true;
                int d1 = curr % 10;
                int d2 = (curr / 10) % 10;
                int d3 = (curr / 100) % 10;
                int d4 = curr / 1000;
                
                if (d1 == 9) {
                    if (!dp[curr - 9]) 
                        q.push(curr - 9);
                }
                else {
                    if (!dp[curr + 1])
                        q.push(curr + 1);
                }
                if (d1 == 0) {
                    if (!dp[curr + 9])
                        q.push(curr + 9);
                }
                else {
                    if (!dp[curr - 1])
                        q.push(curr - 1);
                }
                        
                if (d2 == 9) {
                    if (!dp[curr - 90])
                        q.push(curr - 90);
                }
                else {
                    if (!dp[curr + 10])
                        q.push(curr + 10);
                }
                if (d2 == 0) {
                    if (!dp[curr + 90])
                        q.push(curr + 90);
                }
                else {
                    if (!dp[curr - 10])
                        q.push(curr - 10);
                }
                
                if (d3 == 9) {
                    if (!dp[curr - 900])
                        q.push(curr - 900);
                }
                else {
                    if (!dp[curr + 100])
                        q.push(curr + 100);
                }
                if (d3 == 0) {
                    if (!dp[curr + 900])
                        q.push(curr + 900);
                } 
                else {
                    if (!dp[curr - 100])
                        q.push(curr - 100);
                }
                
                if (d4 == 9) {
                    if (!dp[curr - 9000])
                        q.push(curr - 9000);
                }
                else {
                    if (!dp[curr + 1000])
                        q.push(curr + 1000);
                }
                if (d4 == 0) {
                    if (!dp[curr + 9000])
                        q.push(curr + 9000);
                }
                else {
                    if (!dp[curr - 1000])
                        q.push(curr - 1000);
                }
            }
            ++step;
        }
        return -1;
    }
};
















//bfs; 156 ms 75%; 16.6 MB 95%
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<bool> dp(10000, false);
        for (auto&& deadend : deadends)
            dp[stoi(deadend)] = true;
        if (dp[0])
            return -1;
        queue<string> q;
        q.push(target);
        dp[stoi(target)] = true;
        int step = 0;
        while (!q.empty()) {
            int m = q.size();
            for (int i = 0; i < m; ++i) {
                string curr = q.front();
                q.pop();
                if (curr == "0000") 
                    return step;
                for (int j = 0; j < 8; ++j) {
                    string next = curr.substr(0, j/2) + 
                        static_cast<char>('0' + (curr[j/2] - '0' + 8 * (j % 2) + 1) % 10) + curr.substr(j/2 + 1);
                    if (!dp[stoi(next)]) {
                        q.push(next);
                        dp[stoi(next)] = true;
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};




















//hash table, bfs; 263 ms 47%; 34.4 MB 61%
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited;
        for (auto&& deadend : deadends)
            visited.insert(deadend);
        if (visited.find("0000") != visited.end())
            return -1;
        queue<string> q;
        q.push(target);
        visited.insert(target);
        int step = 0;
        while (!q.empty()) {
            int m = q.size();
            for (int i = 0; i < m; ++i) {
                string curr = q.front();
                q.pop();
                if (curr == "0000") 
                    return step;
                for (int j = 0; j < 8; ++j) {
                    string next = curr.substr(0, j/2) + 
                        static_cast<char>('0' + (curr[j/2] - '0' + 8 * (j % 2) + 1) % 10) + curr.substr(j/2 + 1);
                    if (visited.find(next) == visited.end()) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};