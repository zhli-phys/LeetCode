//Brute force
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> vec;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                vec.push_back(matrix[i][j]);
        sort(vec.begin(), vec.end());
        return vec[k-1];
    }
};







class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = matrix.size();
        for (int i = 0; i < n; i++) 
            pq.push(pair<int, pair<int, int>>(matrix[i][0], pair<int, int>(i, 0)));
        int ans;
        for (int i = 0; i < k - 1; i++) {
            auto curr = pq.top();
            if (curr.second.second < n - 1)
                pq.push(pair<int, pair<int, int>>(matrix[curr.second.first][curr.second.second + 1], pair<int, int>(curr.second.first, curr.second.second + 1)));
            pq.pop();
        }
        return pq.top().first;
    }
};






\\priority_queue; O(n^2 log n) 44 ms 32%; O(n^2) 13.4 MB 54%
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<vector<bool>> visited(n, vector<bool>(n));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({matrix[0][0], 0});
        visited[0][0] = true;
        for (int count = 1; count < k; ++count) {
            int i = pq.top().second / n;
            int j = pq.top().second % n;
            if (i < n - 1 && !visited[i+1][j]) {
                pq.push({matrix[i+1][j], n*(i+1)+j});
                visited[i+1][j] = true;
            }
            if (j < n - 1 && !visited[i][j+1]) {
                pq.push({matrix[i][j+1], n*i+j+1});
                visited[i][j+1] = true;
            }
            pq.pop();
        }
        return pq.top().first;
    }
};











class Solution {
public:
    struct mynode {
        int val;
        int i;
        int j;
        mynode(int i, int j, int val) : i(i), j(j), val(val) {}
    };
    
    struct mygreater {
        bool operator() (mynode& a, mynode& b) {
            return a.val > b.val;
        }
    };
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<mynode, vector<mynode>, mygreater> pq;
        int n = matrix.size();
        for (int i = 0; i < n; i++) 
            pq.push(mynode(i, 0, matrix[i][0]));
        int ans;
        for (int i = 0; i < k - 1; i++) {
            if (pq.top().j< n - 1)
                pq.push(mynode(pq.top().i, pq.top().j + 1, matrix[pq.top().i][pq.top().j + 1]));
            pq.pop();
        }
        return pq.top().val;
    }
};