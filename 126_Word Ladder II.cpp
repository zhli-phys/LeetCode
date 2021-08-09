//breath-first search; O(n^2) 8ms 95%; O(n^2) 8.1MB 99.92%
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<int> rank(n, -1);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (adjacent(beginWord, wordList[i])) {
                if (wordList[i] == endWord)
                    return {{beginWord, endWord}};
                q.push(i);
                rank[i] = 0;
            }
        }
        vector<vector<int>> parent(n);
        int pos = 1;
        int end = -1;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                for (int j = 0; j < n; ++j) {
                    if ((rank[j] < 0 || rank[j] == pos) && adjacent(wordList[q.front()], wordList[j])) {
                        if (rank[j] < 0)
                            q.push(j);
                        parent[j].push_back(q.front());
                        rank[j] = pos;
                        if (wordList[j] == endWord)
                            end = j;
                    }
                }
                q.pop();
            }
            ++pos;
            if (end >= 0)
                break;
        }
        vector<vector<string>> ans;
        vector<string> path;
        if (end >= 0)
            explore(end, path, beginWord, wordList, parent, rank, ans);
        return ans;
    }
    
    bool adjacent(string& s1, string& s2) {
        int n = s1.size();
        int count = 0;
        for (int i = 0; i < n; ++i)
            if (s1[i] != s2[i])
                ++count;
        return (count == 1);
    }
    
    void explore(int curr, vector<string>& path, string& beginWord, vector<string>& wordList,
                vector<vector<int>>& parent, vector<int>& rank, vector<vector<string>>& ans) {
        path.push_back(wordList[curr]);
        if (rank[curr] == 0) {
            path.push_back(beginWord);
            ans.push_back(path);
            reverse(ans.back().begin(), ans.back().end());
            path.pop_back();
        }
        else {
            for (int par : parent[curr])
                explore(par, path, beginWord, wordList, parent, rank, ans);
        }
        path.pop_back();
    }
};