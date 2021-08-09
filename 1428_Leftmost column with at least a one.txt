class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int n = binaryMatrix.dimensions()[1];
        int ans = helper(0, n, binaryMatrix);
        if (ans == n)
            return -1;
        else
            return ans;
    }
    
    int helper(int left, int right, BinaryMatrix &binaryMatrix) {
        int m = binaryMatrix.dimensions()[0];
        if (left == right - 1) {
            for (int i = 0; i < m; i++) {
                if (binaryMatrix.get(i, left) == 1)
                    return left;
            }
            return right;
        }
        int mid = (left + right) / 2;
        for (int i = 0; i < m; i++) {
            if (binaryMatrix.get(i, mid) == 1)
                return helper(left, mid, binaryMatrix);
        }
        return helper(mid, right, binaryMatrix);
    }
};












class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int m = binaryMatrix.dimensions()[0];
        int n = binaryMatrix.dimensions()[1];
        int row = 0;
        int col = n - 1;
        while (row < m && col >= 0) {
            if (binaryMatrix.get(row, col) == 0)
                row++;
            else
                col--;
        }
        if (col < 0)
            return 0;
        else
            return col + 1 == m ? -1: col + 1;
    }
};