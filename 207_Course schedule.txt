class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        unordered_map<int, unordered_set<int>> edges;
        for (int i = 0; i < n; i++) 
            edges[prerequisites[i][0]].insert(prerequisites[i][1]);
        unordered_set<int> vertexs;
        for (int i = 0; i < n; i++) {
            unordered_set<int> prev;
            if (!good_vertex(prerequisites[i][0], vertexs, edges, prev))
                return false;
        }
        return true;
    }
    
    bool good_vertex(int course, unordered_set<int>& vertexs, 
                     unordered_map<int, unordered_set<int>>& edges, 
                     unordered_set<int>& prev) {
        unordered_set<int>::iterator it = vertexs.find(course);
        if (it != vertexs.end())
            return true;
        unordered_set<int>::iterator visited = prev.find(course);
        if (visited != prev.end())
            return false;
        prev.insert(course);
        unordered_set<int> childs = edges[course];
        for (unordered_set<int>::iterator child = childs.begin(); child != childs.end(); child++) {
            if (!good_vertex(*child, vertexs, edges, prev))
                return false;
        }
        vertexs.insert(course);
        return true;
    }
};










class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> edges(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) 
            edges[prerequisites[i][0]].insert(prerequisites[i][1]);
        vector<bool> vertexs(numCourses, false);
        vector<bool> prev(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!good_vertex(numCourses, i, vertexs, edges, prev))
                return false;
        }
        return true;
    }
    
    bool good_vertex(int numCourses, int course, vector<bool>& vertexs, 
                     vector<unordered_set<int>>& edges, 
                     vector<bool>& prev) {
        if (vertexs[course])
            return true;
        if (prev[course])
            return false;
        prev[course] = true;
        unordered_set<int> childs = edges[course];
        for (unordered_set<int>::iterator it = childs.begin(); it != childs.end(); it++) {
            if (!good_vertex(numCourses, *it, vertexs, edges, prev))
                return false;
        }
        vertexs[course] = true;
        return true;
    }
};