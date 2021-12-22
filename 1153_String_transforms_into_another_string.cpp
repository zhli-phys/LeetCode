class Solution {
public:
    bool canConvert(string str1, string str2) {
        vector<int> dir(26, -1);
        int n = str1.size();
        for (int i = 0; i < n; ++i) {
            int num1 = str1[i] - 'a';
            int num2 = str2[i] - 'a';
            if (dir[num1] < 0)
                dir[num1] = num2;
            else if (dir[num1] != num2)
                return false;
        }
        
        unordered_set<int> transformed;
        for (int i = 0; i < 26; ++i)
            if (dir[i] >= 0)
                transformed.insert(dir[i]);
        if (transformed.size() < 26)
            return true;
        
        vector<bool> checked(26);
        vector<bool> visited(26);
        for (int i = 0; i < 26; ++i) {
            if (hasCycle(i, dir, checked, visited))
                return false;
        }
        return true;
    }
    
    bool hasCycle(int i, vector<int>& dir, vector<bool>& checked, vector<bool>& visited) {
        if (i < 0 || checked[i] || dir[i] == i)
            return false;
        if (visited[i])
            return true;
        visited[i] = true;
        if (hasCycle(dir[i], dir, checked, visited))
            return true;
        else {
            checked[i] = true;
            return false;
        }
    }
};