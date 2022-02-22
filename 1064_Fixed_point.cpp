class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        return binary(0, arr.size() - 1, arr);
    }
    
    int binary(int i, int j, vector<int>& arr) {
        if (i > j)
            return -1;
        else if (i == j)
            return arr[i] == i ? i : -1;
        int mid = (i + j) / 2;
        if (arr[mid] >= mid) 
            return binary(i, mid, arr);
        else
            return binary(mid + 1, j, arr);
    }
};