//Time limit exceeded
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        int count = 0;
        for (int i = 0; i < n-K+1; i++) {
            if (A[i] == 0) {
                count++;
                for (int j = i; j < i+K; j++)
                    A[j] = !A[j];
            }
        }
        for (int i = n-K+1; i < n; i++) {
            if (A[i] == 0)
                return -1;
        }
        return count;
    }
};





class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        queue<int> flips;
        int n = A.size();
        int count = 0;
        for (int i = 0; i < n-K+1; i++) {
            if (!flips.empty() && flips.front() <= i-K)
                flips.pop();
            if (flips.size() % 2 == 1)
                A[i] = !A[i];
            if (A[i] == 0) {
                count++;
                flips.push(i);
            }
        }
        for (int i = n-K+1; i < n; i++) {
            if (!flips.empty() && flips.front() <= i-K)
                flips.pop();
            if (flips.size() % 2 == 1)
                A[i] = !A[i];
            if (A[i] == 0)
                return -1;
        }
        return count;
    }
};