class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int na = A.size();
        int nb = B.size();
        vector<vector<int>> ans;
        int i = 0; 
        int j = 0;
        while (i < na && j < nb) {
            if (A[i][1] < B[j][0])          
                i++;
            else if (B[j][1] < A[i][0])
                j++;
            else {
                vector<int> temp(2);
                temp[0] = max(A[i][0], B[j][0]);
                temp[1] = min(A[i][1], B[j][1]);
                ans.push_back(temp);
                if (A[i][1] <= B[j][1])
                    i++;
                else 
                    j++;
            }
        }
        return ans;
    }
};











class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int na = A.size();
        int nb = B.size();
        vector<vector<int>> ans;
        int i = 0; 
        int j = 0;
        vector<int> temp(2);
        while (i < na && j < nb) {
            temp[0] = max(A[i][0], B[j][0]);
            temp[1] = min(A[i][1], B[j][1]);
            if (temp[0] <= temp[1])
                ans.push_back(temp);
            if (A[i][1] <= B[j][1])
                i++;
            else 
                j++;
        }
        return ans;
    }
};