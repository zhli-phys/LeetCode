class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> outgoing(numCourses);
        vector<unordered_set<int>> ingoing(numCourses);
        for (auto& prerequisite : prerequisites) {
            outgoing[prerequisite[1]].insert(prerequisite[0]);
            ingoing[prerequisite[0]].insert(prerequisite[1]);
        }
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (ingoing[i].empty())
                q.push(i);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for (int next : outgoing[curr]) {
                ingoing[next].erase(curr);
                if (ingoing[next].empty())
                    q.push(next);
            }
        }
        if (ans.size() < numCourses)
            return {};
        return ans;
    }
};


















class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> before(numCourses);
        vector<unordered_set<int>> after(numCourses);
        int n = prerequisites.size();
        for (int i = 0; i < n; i++) {
            before[prerequisites[i][0]].insert(prerequisites[i][1]);
            after[prerequisites[i][1]].insert(prerequisites[i][0]);
        }
        vector<bool> taken(numCourses, false);
        bool hashead = true;
        vector<int> ans;
        while (hashead) {
            hashead = false;
            for (int i = 0; i < numCourses; i++) {
                if (!taken[i] && before[i].empty()) {
                    hashead = true;
                    ans.push_back(i);
                    taken[i] = true;
                    for (unordered_set<int>::iterator it = after[i].begin(); it != after[i].end(); it++) {
                            before[*it].erase(i);
                    }
                }
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (!taken[i])
                return vector<int>();
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> before(numCourses);
        vector<unordered_set<int>> after(numCourses);
        int n = prerequisites.size();
        for (int i = 0; i < n; i++) {
            before[prerequisites[i][0]].insert(prerequisites[i][1]);
            after[prerequisites[i][1]].insert(prerequisites[i][0]);
        }
        unordered_set<int> untaken;
        for (int i = 0; i < numCourses; i++)
            untaken.insert(i);
        bool hashead = true;
        vector<int> ans;
        while (hashead) {
            hashead = false;
            for (unordered_set<int>::iterator it = untaken.begin(); it != untaken.end();) {
                if (before[*it].empty()) {
                    int i = *it;
                    hashead = true;
                    ans.push_back(i);
                    it = untaken.erase(it); 
                    for (unordered_set<int>::iterator it1 = after[i].begin(); it1 != after[i].end(); it1++) {
                            before[*it1].erase(i);
                    }
                }
                else
                    it++;
            }
        }
        if (!untaken.empty())
            return vector<int>();
        return ans;
    }
};















class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<unordered_set<int>> after(numCourses);
        int n = prerequisites.size();
        for (int i = 0; i < n; i++) {
            after[prerequisites[i][1]].insert(prerequisites[i][0]);
            indegrees[prerequisites[i][0]]++;
        }
        queue<int> heads;
        for (int i = 0; i < numCourses; i++ ) {
            if (indegrees[i] == 0)
                heads.push(i);
        }
        vector<int> ans;
        while (!heads.empty()) {
            int i = heads.front();
            heads.pop();
            ans.push_back(i);
            for (unordered_set<int>::iterator it = after[i].begin(); it != after[i].end(); it++) {
                indegrees[*it]--;
                if (indegrees[*it] == 0)
                    heads.push(*it);
            }
        }
        if (ans.size() == numCourses)
            return ans;
        else
            return vector<int>();
    }
};










class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> after(numCourses);
        int n = prerequisites.size();
        for (int i = 0; i < n; i++) 
            after[prerequisites[i][1]].insert(prerequisites[i][0]);
        vector<bool> visited(numCourses, false);
        vector<bool> tried(numCourses, false);
        bool loop = false;
        stack<int> sk;
        for (int i = 0; i < numCourses; i++ ) {
            dfs(i, after, visited, tried, loop, sk);
        }
        vector<int> ans;
        while (!sk.empty()) {
            ans.push_back(sk.top());
            sk.pop();
        }
        if (!loop)
            return ans;
        else
            return vector<int>();
    }
    
    void dfs(int i , vector<unordered_set<int>>& after, vector<bool>& visited, vector<bool>& tried, bool& loop, stack<int>& sk) {
        if (loop)
            return;
        if (visited[i])
            return;
        if (tried[i]) 
            loop = true;
        tried[i] = true;
        for (unordered_set<int>::iterator it = after[i].begin(); it != after[i].end(); it++) {
            dfs(*it, after, visited, tried, loop, sk);
        }
        sk.push(i);
        visited[i] = true;
    }
};