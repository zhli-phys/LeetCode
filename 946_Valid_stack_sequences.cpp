class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int i = 0;
        int j = 0;
        stack<int> sk;
        for (int i = 0; i < n; ++i) {
            sk.push(pushed[i]);
            while (!sk.empty() && j < n && sk.top() == popped[j]) {
                sk.pop();
                ++j;
            }
        }
        return sk.empty();
    }
};