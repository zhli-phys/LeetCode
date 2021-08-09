#define M 1000000007
#define M 1000000007

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int Max = 100000;
        vector<int> vec(4*Max);
        long cost = 0;
        for (int num : instructions) {
            cost += min(querry(0, 1, Max, vec, 1, num-1), querry(0, 1, Max, vec, num+1, M));
            update(0, 1, Max, vec, num, 1);
        }
        return cost % M;
    }
    
    void update(int i, int left, int right, vector<int>& vec, int pos, int diff) {
        if (right < pos || left > pos)
            return;
        vec[i] += diff;
        if (left != right) {
            int mid = (left + right) / 2;
            update(2*i+1, left, mid, vec, pos, diff);
            update(2*i+2, mid+1, right, vec, pos, diff);
        }
    }
    
    long querry(int i, int left, int right, vector<int>& vec, int qleft, int qright) {
        if (right < qleft || left > qright)
            return 0;
        if (left >= qleft && right <= qright)
            return vec[i];
        int mid = (left + right) / 2;
        return querry(2*i+1, left, mid, vec, qleft, qright) + querry(2*i+2, mid+1, right, vec, qleft, qright);
    }
};